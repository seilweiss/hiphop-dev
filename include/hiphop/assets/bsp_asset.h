#pragma once

#include "hiphop/core/renderware_asset.h"

#ifdef HIPHOP_USE_RWS
#include "rws_core.h"
#endif

namespace HipHop {

    struct BSPAsset : RenderWareAsset
    {
        HIPHOP_ASSET(AssetType::BSP);

        BSPAsset(Asset asset) : RenderWareAsset(asset) {}

#ifdef HIPHOP_USE_RWS
        void Read(Stream* stream);
        void Write(Stream* stream);
#endif
    };

}