#pragma once

#include "hiphop/core/renderware_asset.h"

#ifdef HIPHOP_USE_RWS
#include "rws_core.h"
#endif

namespace HipHop {

    struct TextureAsset : RenderWareAsset
    {
        HIPHOP_ASSET(AssetType::RWTX);

        TextureAsset(Asset asset) : RenderWareAsset(asset) {}

#ifdef HIPHOP_USE_RWS
        Rws::TexDictionary* GetTexDictionary() const { return m_texDictionary; }
        void SetTexDictionary(Rws::TexDictionary* texDictionary);

        void Read(Stream* stream);
        void Write(Stream* stream);

    private:
        Rws::TexDictionary* m_texDictionary = nullptr;
#endif
    };

}