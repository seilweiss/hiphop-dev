#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct EnvAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::ENV);

        EnvAsset(Asset asset) : DefaultAsset(asset) {}
    };

}