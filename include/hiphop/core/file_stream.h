#pragma once

#include "hiphop/core/stream.h"

#include <cstdio>
#include <string>

namespace HipHop {

    class FileStream : public Stream
    {
    public:
        FileStream() : Stream() {}
        FileStream(const std::string& path) : Stream() { Open(path); }
        ~FileStream() { Close(); }

        bool Open(const std::string& path);
        void Close();

        std::string GetPath() const { return m_path; }
        bool IsReadOnly() const { return m_readOnly; }

        virtual size_t DoRead(void* buf, size_t size) override;
        virtual size_t DoWrite(const void* buf, size_t size) override;
        virtual size_t Tell() const override { return m_pos; }
        virtual void Seek(size_t pos) override;
        virtual size_t GetSize() const override { return m_size; }
        virtual void Resize(size_t size) override;
        virtual bool IsOpen() const { return m_file != nullptr; }
        virtual bool IsOK() const { return ferror(m_file) == 0; }

    private:
        enum Mode
        {
            MODE_READ,
            MODE_WRITE
        };

        FILE* m_file = nullptr;
        std::string m_path;
        bool m_readOnly = false;
        Mode m_mode = MODE_READ;
        long m_pos = 0;
        size_t m_size = 0;
    };

}