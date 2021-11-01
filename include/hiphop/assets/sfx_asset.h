#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct SFXAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::SFX);

        SFXAsset(Asset asset) : DefaultAsset(asset) {}
    };

}