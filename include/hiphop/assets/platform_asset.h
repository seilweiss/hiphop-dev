#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct PlatformAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::PLAT);

        PlatformAsset(Asset asset) : DefaultAsset(asset) {}
    };

}