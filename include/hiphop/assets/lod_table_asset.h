#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct LODTableAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::LODT);

        LODTableAsset(Asset asset) : DefaultAsset(asset) {}
    };

}