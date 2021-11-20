#include "hiphop/core/memory_stream.h"

#include <cstring>

namespace HipHop {

    size_t MemoryStream::DoRead(void* buf, size_t size)
    {
        if (size == 0)
        {
            return 0;
        }

        if (m_data.size() - m_pos < size)
        {
            size = m_data.size() - m_pos;
        }

        if (!memcpy(buf, m_data.data() + m_pos, size))
        {
            return 0;
        }

        m_pos += size;

        return size;
    }

    size_t MemoryStream::DoWrite(const void* buf, size_t size)
    {
        if (size == 0)
        {
            return 0;
        }

        size_t end = m_pos + size;

        if (end > m_data.size())
        {
            m_data.resize(end, GetPadByte());
        }

        if (!memcpy(m_data.data() + m_pos, buf, size))
        {
            return 0;
        }

        m_pos += size;

        return size;
    }

    void MemoryStream::Seek(size_t pos)
    {
        if (pos > m_data.size())
        {
            m_data.resize(pos, GetPadByte());
        }

        m_pos = pos;
    }

    void MemoryStream::SetData(const void* data, size_t size)
    {
        m_data.clear();
        m_data.resize(size);

        if (data && size > 0)
        {
            memcpy(m_data.data(), data, size);
        }
    }

}