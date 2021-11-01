#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct CutsceneTOCAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::CTOC);

        CutsceneTOCAsset(Asset asset) : DefaultAsset(asset) {}
    };

}