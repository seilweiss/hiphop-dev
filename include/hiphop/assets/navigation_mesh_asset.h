#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct NavigationMeshAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::NGMS);

        NavigationMeshAsset(Asset asset) : DefaultAsset(asset) {}
    };

}