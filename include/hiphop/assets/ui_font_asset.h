#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct UIFontAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::UIFT);

        UIFontAsset(Asset asset) : DefaultAsset(asset) {}
    };

}