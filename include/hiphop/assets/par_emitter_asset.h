#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct ParEmitterAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::PARE);

        ParEmitterAsset(Asset asset) : DefaultAsset(asset) {}
    };

}