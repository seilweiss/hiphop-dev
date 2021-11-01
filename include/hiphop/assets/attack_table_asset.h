#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct AttackTableAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::ATKT);

        AttackTableAsset(Asset asset) : DefaultAsset(asset) {}
    };

}