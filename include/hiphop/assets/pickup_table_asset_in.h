#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct PickupTableAssetIN : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::TPIK);

        PickupTableAssetIN(Asset asset) : DefaultAsset(asset) {}
    };

}