#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct NPCPropsAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::VILP);

        NPCPropsAsset(Asset asset) : DefaultAsset(asset) {}
    };

}