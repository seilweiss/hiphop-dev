#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct SoundFXAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::SDFX);

        SoundFXAsset(Asset asset) : DefaultAsset(asset) {}
    };

}