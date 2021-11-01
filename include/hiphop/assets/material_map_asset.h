#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct MaterialMapAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::MAPR);

        MaterialMapAsset(Asset asset) : DefaultAsset(asset) {}
    };

}