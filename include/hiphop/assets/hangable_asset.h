#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct HangableAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::HANG);

        HangableAsset(Asset asset) : DefaultAsset(asset) {}
    };

}