#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct LightAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::LITE);

        LightAsset(Asset asset) : DefaultAsset(asset) {}
    };

}