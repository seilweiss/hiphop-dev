#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct UIMotionAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::UIM);

        UIMotionAsset(Asset asset) : DefaultAsset(asset) {}
    };

}