#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct MarkerAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::MRKR);

        MarkerAsset(Asset asset) : DefaultAsset(asset) {}
    };

}