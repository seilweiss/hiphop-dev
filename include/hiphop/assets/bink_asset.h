#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct BinkAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::BINK);

        BinkAsset(Asset asset) : DefaultAsset(asset) {}
    };

}