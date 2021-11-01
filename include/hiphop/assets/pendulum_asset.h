#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct PendulumAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::PEND);

        PendulumAsset(Asset asset) : DefaultAsset(asset) {}
    };

}