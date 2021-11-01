#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct EGenAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::EGEN);

        EGenAsset(Asset asset) : DefaultAsset(asset) {}
    };

}