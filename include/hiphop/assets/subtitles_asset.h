#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct SubtitlesAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::SUBT);

        SubtitlesAsset(Asset asset) : DefaultAsset(asset) {}
    };

}