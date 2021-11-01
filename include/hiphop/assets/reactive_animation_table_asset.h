#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct ReactiveAnimationTableAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::RANM);

        ReactiveAnimationTableAsset(Asset asset) : DefaultAsset(asset) {}
    };

}