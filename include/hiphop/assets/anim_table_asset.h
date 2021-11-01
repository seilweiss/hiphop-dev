#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct AnimTableAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::ATBL);

        AnimTableAsset(Asset asset) : DefaultAsset(asset) {}
    };

}