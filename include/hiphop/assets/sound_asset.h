#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct SoundAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::SND);

        SoundAsset(Asset asset) : DefaultAsset(asset) {}
    };

}