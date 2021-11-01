#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct SoundInfoAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::SNDI);

        SoundInfoAsset(Asset asset) : DefaultAsset(asset) {}
    };

}