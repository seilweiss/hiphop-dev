#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct ThrowableTableAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::TRWT);

        ThrowableTableAsset(Asset asset) : DefaultAsset(asset) {}
    };

}