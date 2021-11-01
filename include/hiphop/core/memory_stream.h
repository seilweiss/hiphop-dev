#pragma once

#include "hiphop/core/stream.h"

#include <vector>

namespace HipHop {

    class MemoryStream : public Stream
    {
    public:
        MemoryStream() : Stream() {}
        MemoryStream(const void* data, size_t size) : Stream() { SetData(data, size); }

        void* GetData() { return m_data.data(); }
        void SetData(const void* data, size_t size);

        virtual size_t DoRead(void* buf, size_t size) override;
        virtual size_t DoWrite(const void* buf, size_t size) override;
        virtual size_t Tell() const override { return m_pos; }
        virtual void Seek(size_t pos) override;
        virtual size_t GetSize() const override { return m_data.size(); }
        virtual void Resize(size_t size) override { m_data.resize(size, 0); }
        virtual bool IsOpen() const { return true; }
        virtual bool IsOK() const { return true; }

    private:
        std::vector<uint8_t> m_data;
        size_t m_pos = 0;
    };

}