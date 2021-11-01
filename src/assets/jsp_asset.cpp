#include "hiphop/assets/jsp_asset.h"

namespace HipHop {

#ifdef HIPHOP_USE_RWS
    void JSPAsset::SetClump(Rws::Clump* clump)
    {
        SetChunk(clump);

        m_clump = clump;
    }

    void JSPAsset::Read(Stream* stream)
    {
        RenderWareAsset::Read(stream);

        Rws::Chunk* chunk = GetChunk();

        if (chunk)
        {
            m_clump = chunk->As<Rws::Clump>();
        }
        else
        {
            m_clump = nullptr;
        }
    }

    void JSPAsset::Write(Stream* stream)
    {
        RenderWareAsset::Write(stream);
    }
#endif

}