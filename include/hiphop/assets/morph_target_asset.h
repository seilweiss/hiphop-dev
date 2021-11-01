#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct MorphTargetAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::MPHT);

        MorphTargetAsset(Asset asset) : DefaultAsset(asset) {}
    };

}