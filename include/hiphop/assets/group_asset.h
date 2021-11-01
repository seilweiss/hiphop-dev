#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct GroupAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::GRUP);

        GroupAsset(Asset asset) : DefaultAsset(asset) {}
    };

}