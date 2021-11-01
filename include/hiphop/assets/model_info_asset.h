#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct ModelInfoAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::MINF);

        ModelInfoAsset(Asset asset) : DefaultAsset(asset) {}
    };

}