#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct ZipLineAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::ZLIN);

        ZipLineAsset(Asset asset) : DefaultAsset(asset) {}
    };

}