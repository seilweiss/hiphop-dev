#include "hiphop/assets/texture_asset.h"

namespace HipHop {

#ifdef HIPHOP_USE_RWS
    void TextureAsset::SetTexDictionary(Rws::TexDictionary* texDictionary)
    {
        SetChunk(texDictionary);

        m_texDictionary = texDictionary;
    }

    void TextureAsset::Read(Stream* stream)
    {
        RenderWareAsset::Read(stream);

        Rws::Chunk* chunk = GetChunk();

        if (chunk)
        {
            m_texDictionary = chunk->As<Rws::TexDictionary>();
        }
        else
        {
            m_texDictionary = nullptr;
        }
    }

    void TextureAsset::Write(Stream* stream)
    {
        RenderWareAsset::Write(stream);
    }
#endif

}