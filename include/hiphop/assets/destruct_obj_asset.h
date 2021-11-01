#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct DestructObjAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::DSTR);

        DestructObjAsset(Asset asset) : DefaultAsset(asset) {}
    };

}