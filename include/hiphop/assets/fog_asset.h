#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct FogAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::FOG);

        FogAsset(Asset asset) : DefaultAsset(asset) {}
    };

}