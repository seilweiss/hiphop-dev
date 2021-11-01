#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct SimpleShadowTableAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::SHDW);

        SimpleShadowTableAsset(Asset asset) : DefaultAsset(asset) {}
    };

}