#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct OneLinerAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::ONEL);

        OneLinerAsset(Asset asset) : DefaultAsset(asset) {}
    };

}