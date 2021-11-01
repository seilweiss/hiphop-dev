#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct GrassMeshAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::GRSM);

        GrassMeshAsset(Asset asset) : DefaultAsset(asset) {}
    };

}