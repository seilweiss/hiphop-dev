#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct StreamingTextureAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::TEXS);

        StreamingTextureAsset(Asset asset) : DefaultAsset(asset) {}
    };

}