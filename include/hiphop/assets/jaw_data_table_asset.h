#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct JawDataTableAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::JAW);

        JawDataTableAsset(Asset asset) : DefaultAsset(asset) {}
    };

}