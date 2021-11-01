#pragma once

#include "hiphop/core/renderware_asset.h"

#ifdef HIPHOP_USE_RWS
#include "rws_core.h"
#include "rws_world.h"
#endif

namespace HipHop {

    struct ModelAsset : RenderWareAsset
    {
        HIPHOP_ASSET(AssetType::MODL);

        ModelAsset(Asset asset) : RenderWareAsset(asset) {}

#ifdef HIPHOP_USE_RWS
        Rws::Clump* GetClump() const { return m_clump; }
        void SetClump(Rws::Clump* clump);

        void Read(Stream* stream);
        void Write(Stream* stream);

    private:
        Rws::Clump* m_clump = nullptr;
#endif
    };

}