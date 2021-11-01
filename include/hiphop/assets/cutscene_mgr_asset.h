#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct CutsceneMgrAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::CSNM);

        CutsceneMgrAsset(Asset asset) : DefaultAsset(asset) {}
    };

}