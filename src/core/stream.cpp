#include "hiphop/core/stream.h"

#include "hiphop/core/util.h"

#include <cstring>
#include <algorithm>

namespace HipHop {

    Stream::Stream()
    {
        m_endian = Util::GetNativeEndian();
    }

    size_t Stream::Read8(void* buf, size_t size)
    {
        return Read(buf, size);
    }

    size_t Stream::Read16(void* buf, size_t size)
    {
        size_t num = Read(buf, size);

        if (m_endian != Util::GetNativeEndian())
        {
            Util::Swap16(buf, num);
        }

        return num;
    }

    size_t Stream::Read32(void* buf, size_t size)
    {
        size_t num = Read(buf, size);

        if (m_endian != Util::GetNativeEndian())
        {
            Util::Swap32(buf, num);
        }

        return num;
    }

    size_t Stream::Read64(void* buf, size_t size)
    {
        size_t num = Read(buf, size);

        if (m_endian != Util::GetNativeEndian())
        {
            Util::Swap64(buf, num);
        }

        return num;
    }

    size_t Stream::Write8(const void* buf, size_t size)
    {
        return Write(buf, size);
    }

    size_t Stream::Write16(const void* buf, size_t size)
    {
        size_t num = 0;

        if (m_endian != Util::GetNativeEndian())
        {
            const uint8_t* srcBuf = (const uint8_t*)buf;

            while (size)
            {
                uint8_t copyBuf[64];
                size_t copySize = std::min(size, (size_t)64);

                memcpy(copyBuf, srcBuf, copySize);
                Util::Swap16(copyBuf, copySize);

                num += Write((const void*)copyBuf, size);
                srcBuf += copySize;
                size -= copySize;
            }
        }
        else
        {
            num = Write(buf, size);
        }

        return num;
    }

    size_t Stream::Write32(const void* buf, size_t size)
    {
        size_t num = 0;

        if (m_endian != Util::GetNativeEndian())
        {
            const uint8_t* srcBuf = (const uint8_t*)buf;

            while (size)
            {
                uint8_t copyBuf[64];
                size_t copySize = std::min(size, (size_t)64);

                memcpy(copyBuf, srcBuf, copySize);
                Util::Swap32(copyBuf, copySize);

                num += Write((const void*)copyBuf, size);
                srcBuf += copySize;
                size -= copySize;
            }
        }
        else
        {
            num = Write(buf, size);
        }

        return num;
    }

    size_t Stream::Write64(const void* buf, size_t size)
    {
        size_t num = 0;

        if (m_endian != Util::GetNativeEndian())
        {
            const uint8_t* srcBuf = (const uint8_t*)buf;

            while (size)
            {
                uint8_t copyBuf[64];
                size_t copySize = std::min(size, (size_t)64);

                memcpy(copyBuf, srcBuf, copySize);
                Util::Swap64(copyBuf, copySize);

                num += Write((const void*)copyBuf, size);
                srcBuf += copySize;
                size -= copySize;
            }
        }
        else
        {
            num = Write(buf, size);
        }

        return num;
    }

}