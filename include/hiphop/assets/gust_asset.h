#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct GustAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::GUST);

        GustAsset(Asset asset) : DefaultAsset(asset) {}
    };

}