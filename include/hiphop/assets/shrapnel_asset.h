#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct ShrapnelAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::SHRP);

        ShrapnelAsset(Asset asset) : DefaultAsset(asset) {}
    };

}