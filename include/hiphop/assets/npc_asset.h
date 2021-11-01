#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct NPCAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::VIL);

        NPCAsset(Asset asset) : DefaultAsset(asset) {}
    };

}