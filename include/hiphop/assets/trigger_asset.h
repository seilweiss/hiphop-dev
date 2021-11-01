#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct TriggerAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::TRIG);

        TriggerAsset(Asset asset) : DefaultAsset(asset) {}
    };

}