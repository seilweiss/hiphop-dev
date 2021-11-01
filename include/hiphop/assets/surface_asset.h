#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct SurfaceAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::SURF);

        SurfaceAsset(Asset asset) : DefaultAsset(asset) {}
    };

}