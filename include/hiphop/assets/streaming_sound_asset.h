#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct StreamingSoundAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::SNDS);

        StreamingSoundAsset(Asset asset) : DefaultAsset(asset) {}
    };

}