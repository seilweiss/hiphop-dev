#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct PickupTableAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::PICK);

        PickupTableAsset(Asset asset) : DefaultAsset(asset) {}
    };

}