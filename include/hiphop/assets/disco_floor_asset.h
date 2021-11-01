#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct DiscoFloorAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::DSCO);

        DiscoFloorAsset(Asset asset) : DefaultAsset(asset) {}
    };

}