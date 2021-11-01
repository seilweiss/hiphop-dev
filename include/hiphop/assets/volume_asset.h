#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct VolumeAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::VOLU);

        VolumeAsset(Asset asset) : DefaultAsset(asset) {}
    };

}