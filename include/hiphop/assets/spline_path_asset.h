#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct SplinePathAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::SPLP);

        SplinePathAsset(Asset asset) : DefaultAsset(asset) {}
    };

}