#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct UIAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::UI);

        UIAsset(Asset asset) : DefaultAsset(asset) {}
    };

}