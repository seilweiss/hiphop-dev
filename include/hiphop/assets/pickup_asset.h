#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct PickupAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::PKUP);

        PickupAsset(Asset asset) : DefaultAsset(asset) {}
    };

}