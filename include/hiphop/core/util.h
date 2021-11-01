#pragma once

#include "hiphop/core/endian.h"
#include "hiphop/core/platforms.h"

#include <cstdint>
#include <string>

namespace HipHop {

    namespace Util {

        inline Endian GetNativeEndian()
        {
            static int32_t x = 1;
            static Endian endian = *(uint8_t*)&x == 1 ? Endian::Little : Endian::Big;
            return endian;
        }

        inline Endian GetPlatformEndian(Platform platform)
        {
            return platform == Platform::GameCube ? Endian::Big : Endian::Little;
        }

        inline uint32_t Hash(const std::string& str)
        {
            const char* buf = str.c_str();
            uint32_t value = 0;

            while (char c = *buf)
            {
                value = (c - (c & c >> 1 & 0x20) & 0xff) + value * 131;
                buf++;
            }

            return value;
        }

        inline size_t Align(size_t x, int32_t alignment)
        {
            return alignment == 0 ? x : (x + (alignment - 1) & ~(alignment - 1));
        }

        inline void Swap16(void* p, size_t size)
        {
            uint16_t* x = (uint16_t*)p;
            uint16_t* end = x + size / sizeof(uint16_t);

            while (x != end)
            {
                *x = ((*x & 0x00FF) << 8) |
                    ((*x & 0xFF00) >> 8);
                x++;
            }
        }

        inline void Swap32(void* p, size_t size)
        {
            uint32_t* x = (uint32_t*)p;
            uint32_t* end = x + size / sizeof(uint32_t);

            while (x != end)
            {
                *x = ((*x & 0x000000FF) << 24) |
                    ((*x & 0x0000FF00) << 8) |
                    ((*x & 0x00FF0000) >> 8) |
                    ((*x & 0xFF000000) >> 24);
                x++;
            }
        }

        inline void Swap64(void* p, size_t size)
        {
            uint64_t* x = (uint64_t*)p;
            uint64_t* end = x + size / sizeof(uint64_t);

            while (x != end)
            {
                *x = ((*x & 0xFF00000000000000ull) >> 56) |
                    ((*x & 0x00FF000000000000ull) >> 40) |
                    ((*x & 0x0000FF0000000000ull) >> 24) |
                    ((*x & 0x000000FF00000000ull) >> 8) |
                    ((*x & 0x00000000FF000000ull) << 8) |
                    ((*x & 0x0000000000FF0000ull) << 24) |
                    ((*x & 0x000000000000FF00ull) << 40) |
                    ((*x & 0x00000000000000FFull) << 56);
                x++;
            }
        }
    }

}