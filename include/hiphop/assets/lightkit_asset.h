#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct LightKitAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::LKIT);

        LightKitAsset(Asset asset) : DefaultAsset(asset) {}
    };

}