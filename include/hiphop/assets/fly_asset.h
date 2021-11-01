#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct FlyAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::FLY);

        FlyAsset(Asset asset) : DefaultAsset(asset) {}
    };

}