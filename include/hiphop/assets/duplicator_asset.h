#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct DuplicatorAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::DUPC);

        DuplicatorAsset(Asset asset) : DefaultAsset(asset) {}
    };

}