#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "hiphop/core/file_stream.h"

#include <algorithm>

namespace HipHop {

    bool FileStream::Open(const std::string& path)
    {
        if (IsOpen())
        {
            Close();
        }

        const char* pathString = path.c_str();

        m_file = fopen(pathString, "rb+"); // Try to open file in read+write mode

        if (!m_file)
        {
            m_file = fopen(pathString, "wb+"); // File might not exist; try opening as a new file

            if (!m_file)
            {
                m_file = fopen(pathString, "rb"); // File might be read-only; try opening in read mode

                if (!m_file)
                {
                    return false; // Cannot open file for some reason
                }

                m_readOnly = true;
            }
        }
        else
        {
            m_readOnly = false;
        }

        fseek(m_file, 0, SEEK_END);

        m_size = (size_t)ftell(m_file);

        fseek(m_file, 0, SEEK_SET);

        m_path = path;
        m_mode = MODE_READ;

        return true;
    }

    void FileStream::Close()
    {
        if (m_file)
        {
            fclose(m_file);

            m_file = nullptr;
            m_path = std::string();
            m_readOnly = false;
            m_mode = MODE_READ;
            m_pos = 0;
            m_size = 0;
        }
    }

    size_t FileStream::DoRead(void* buf, size_t size)
    {
        if (size == 0)
        {
            return 0;
        }

        if (!IsOpen())
        {
            return 0;
        }

        if (m_pos + size > m_size)
        {
            size = m_size - m_pos;
        }

        fseek(m_file, m_pos, SEEK_SET);

        size_t num = fread(buf, 1, size, m_file);

        m_pos += (long)num;

        return num;
    }

    size_t FileStream::DoWrite(const void* buf, size_t size)
    {
        if (size == 0)
        {
            return 0;
        }

        if (!IsOpen())
        {
            return 0;
        }

        if (m_readOnly)
        {
            return 0;
        }

        fseek(m_file, m_pos, SEEK_SET);

        size_t num = fwrite(buf, 1, size, m_file);

        m_pos += (long)num;

        if (m_pos > (long)m_size)
        {
            m_size = m_pos;
        }

        return num;
    }

    void FileStream::Seek(size_t pos)
    {
        if (!IsOpen())
        {
            return;
        }

        if (pos > m_size)
        {
            if (m_readOnly)
            {
                fseek(m_file, 0, SEEK_END);
                return;
            }

            Resize(pos);
        }

        fseek(m_file, (long)pos, SEEK_SET);

        m_pos = (long)pos;
    }

    void FileStream::Resize(size_t size)
    {
        if (!IsOpen())
        {
            return;
        }

        if (m_readOnly)
        {
            return;
        }

        if (size == m_size)
        {
            return;
        }

        if (size <= m_size)
        {
            if (size == 0)
            {
                if (!freopen(m_path.c_str(), "wb+", m_file))
                {
                    return;
                }
            }
            else
            {
                uint8_t* buf = new uint8_t[size];

                fseek(m_file, 0, SEEK_SET);
                fread(buf, size, 1, m_file);

                if (!freopen(m_path.c_str(), "wb+", m_file))
                {
                    delete[] buf;
                    return;
                }

                fwrite(buf, size, 1, m_file);

                delete[] buf;
            }
        }
        else
        {
            uint8_t buf[64];
            memset(buf, GetPadByte(), sizeof(buf));

            size_t tmpsize = size - m_size;

            fseek(m_file, 0, SEEK_END);

            while (tmpsize)
            {
                size_t writeSize = std::min(tmpsize, sizeof(buf));

                fwrite(buf, writeSize, 1, m_file);

                tmpsize -= writeSize;
            }
        }

        if (m_pos > (long)size)
        {
            m_pos = (long)size;
        }

        fseek(m_file, m_pos, SEEK_SET);

        m_mode = MODE_WRITE;
        m_size = size;
    }

}