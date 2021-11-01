#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct ParEmitterPropsAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::PARP);

        ParEmitterPropsAsset(Asset asset) : DefaultAsset(asset) {}
    };

}