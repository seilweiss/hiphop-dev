#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct SimpleObjAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::SIMP);

        SimpleObjAsset(Asset asset) : DefaultAsset(asset) {}
    };

}