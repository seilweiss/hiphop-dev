#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct RawAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::RAW);

        RawAsset(Asset asset) : DefaultAsset(asset) {}
    };

}