#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct AnimAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::ANIM);

        AnimAsset(Asset asset) : DefaultAsset(asset) {}
    };

}