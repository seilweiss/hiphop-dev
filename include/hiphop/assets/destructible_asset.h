#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct DestructibleAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::DEST);

        DestructibleAsset(Asset asset) : DefaultAsset(asset) {}
    };

}