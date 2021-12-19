#pragma once

#include "hiphop/core/endian.h"
#include "hiphop/core/util.h"

#include <cstdint>

namespace HipHop {

    class Stream
    {
    public:
        Stream();

        virtual size_t DoRead(void* buf, size_t size) = 0;
        virtual size_t DoWrite(const void* buf, size_t size) = 0;
        virtual size_t Tell() const = 0;
        virtual void Seek(size_t pos) = 0;
        virtual size_t GetSize() const = 0;
        virtual void Resize(size_t size) = 0;
        virtual bool IsOpen() const = 0;
        virtual bool IsOK() const = 0;

        Endian GetEndian() const { return m_endian; }
        void SetEndian(Endian endian) { m_endian = endian; }

        uint8_t GetPadByte() const { return m_padByte; }
        void SetPadByte(uint8_t padByte) { m_padByte = padByte; }

        bool AtEnd() const { return Tell() >= GetSize(); }
        void SeekEnd(size_t pos = 0) { Seek(GetSize() - pos); }
        void Skip(size_t amt) { Seek(Tell() + amt); }
        void Align(int32_t align) { Seek(Util::Align(Tell(), align)); }

        void Clear() { Resize(0); }

        size_t Read(void* buf, size_t size) { return DoRead(buf, size); }
        size_t Read(int8_t* x, size_t size = sizeof(int8_t)) { return Read8(x, size); }
        size_t Read(uint8_t* x, size_t size = sizeof(uint8_t)) { return Read8(x, size); }
        size_t Read(int16_t* x, size_t size = sizeof(int16_t)) { return Read16(x, size); }
        size_t Read(uint16_t* x, size_t size = sizeof(uint16_t)) { return Read16(x, size); }
        size_t Read(int32_t* x, size_t size = sizeof(int32_t)) { return Read32(x, size); }
        size_t Read(uint32_t* x, size_t size = sizeof(uint32_t)) { return Read32(x, size); }
        size_t Read(int64_t* x, size_t size = sizeof(int64_t)) { return Read64(x, size); }
        size_t Read(uint64_t* x, size_t size = sizeof(uint64_t)) { return Read64(x, size); }
        size_t Read(bool* x, size_t size = sizeof(bool)) { return Read8(x, size); }
        size_t Read(float* x, size_t size = sizeof(float)) { return Read32(x, size); }
        size_t Read(double* x, size_t size = sizeof(double)) { return Read64(x, size); }
        size_t Write(const void* buf, size_t size) { return DoWrite(buf, size); }
        size_t Write(const int8_t* x, size_t size = sizeof(int8_t)) { return Write8(x, size); }
        size_t Write(const uint8_t* x, size_t size = sizeof(uint8_t)) { return Write8(x, size); }
        size_t Write(const int16_t* x, size_t size = sizeof(int16_t)) { return Write16(x, size); }
        size_t Write(const uint16_t* x, size_t size = sizeof(uint16_t)) { return Write16(x, size); }
        size_t Write(const int32_t* x, size_t size = sizeof(int32_t)) { return Write32(x, size); }
        size_t Write(const uint32_t* x, size_t size = sizeof(uint32_t)) { return Write32(x, size); }
        size_t Write(const int64_t* x, size_t size = sizeof(int64_t)) { return Write64(x, size); }
        size_t Write(const uint64_t* x, size_t size = sizeof(uint64_t)) { return Write64(x, size); }
        size_t Write(const bool* x, size_t size = sizeof(bool)) { return Write8(x, size); }
        size_t Write(const float* x, size_t size = sizeof(float)) { return Write32(x, size); }
        size_t Write(const double* x, size_t size = sizeof(double)) { return Write64(x, size); }

    private:
        Endian m_endian;
        uint8_t m_padByte = 0x00;

        size_t Read8(void* buf, size_t size);
        size_t Read16(void* buf, size_t size);
        size_t Read32(void* buf, size_t size);
        size_t Read64(void* buf, size_t size);
        size_t Write8(const void* buf, size_t size);
        size_t Write16(const void* buf, size_t size);
        size_t Write32(const void* buf, size_t size);
        size_t Write64(const void* buf, size_t size);
    };

}