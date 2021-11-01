#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct MovePointAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::MVPT);

        MovePointAsset(Asset asset) : DefaultAsset(asset) {}
    };

}