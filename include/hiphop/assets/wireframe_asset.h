#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct WireframeAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::WIRE);

        WireframeAsset(Asset asset) : DefaultAsset(asset) {}
    };

}