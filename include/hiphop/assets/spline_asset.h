#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct SplineAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::SPLN);

        SplineAsset(Asset asset) : DefaultAsset(asset) {}
    };

}