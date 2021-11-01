#include "hiphop/core/renderware_asset.h"

#include "hiphop/core/memory_stream.h"

namespace HipHop {

#ifdef HIPHOP_USE_RWS
    namespace {

        Rws::Bool CustomOpen(Rws::Stream::AccessType accessType, void* userdata)
        {
            return true;
        }

        Rws::Bool CustomClose(void* userdata)
        {
            return true;
        }

        Rws::Bool CustomSeek(Rws::UInt32 position, void* userdata)
        {
            Stream* stream = (Stream*)userdata;
            stream->Seek(position);

            return true;
        }

        Rws::UInt32 CustomRead(void* buffer, Rws::UInt32 length, void* userdata)
        {
            Stream* stream = (Stream*)userdata;
            Rws::UInt32 bytesRead = (Rws::UInt32)stream->Read(buffer, length);

            return bytesRead;
        }

        Rws::UInt32 CustomWrite(const void* buffer, Rws::UInt32 length, void* userdata)
        {
            Stream* stream = (Stream*)userdata;
            Rws::UInt32 bytesWritten = (Rws::UInt32)stream->Write(buffer, length);

            return bytesWritten;
        }

    }

    RenderWareAsset::~RenderWareAsset()
    {
        if (m_chunk)
        {
            delete m_chunk;
        }
    }

    void RenderWareAsset::SetChunk(Rws::Chunk* chunk)
    {
        if (m_chunk)
        {
            delete m_chunk;
        }

        m_chunk = chunk;
    }

    void RenderWareAsset::Read(Stream* stream)
    {
        if (m_chunk)
        {
            delete m_chunk;
        }

        m_chunk = ReadChunk(stream);
    }

    void RenderWareAsset::Write(Stream* stream)
    {
        if (!m_chunk)
        {
            return;
        }

        WriteChunk(m_chunk, stream);
    }

    Rws::Chunk* RenderWareAsset::ReadChunk(Stream* stream)
    {
        Rws::Stream::CustomData customData = {};
        customData.userdata = stream;
        customData.open = CustomOpen;
        customData.close = CustomClose;
        customData.seek = CustomSeek;
        customData.read = CustomRead;
        customData.write = CustomWrite;

        Rws::Stream rwsStream(&customData, Rws::Stream::ACCESS_READ);

        rwsStream.Seek((Rws::UInt32)stream->Tell());

        return rwsStream.ReadChunk();
    }

    void RenderWareAsset::WriteChunk(Rws::Chunk* chunk, Stream* stream)
    {
        if (!chunk)
        {
            return;
        }

        Rws::Stream::CustomData customData = {};
        customData.userdata = stream;
        customData.open = CustomOpen;
        customData.close = CustomClose;
        customData.seek = CustomSeek;
        customData.read = CustomRead;
        customData.write = CustomWrite;

        Rws::Stream rwsStream(&customData, Rws::Stream::ACCESS_WRITE);

        rwsStream.Seek((Rws::UInt32)stream->Tell());
        rwsStream.WriteChunk(chunk);
    }
#endif

}