#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct VillainAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::NPC);

        VillainAsset(Asset asset) : DefaultAsset(asset) {}
    };

}