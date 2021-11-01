#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct ProjectileAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::PRJT);

        ProjectileAsset(Asset asset) : DefaultAsset(asset) {}
    };

}