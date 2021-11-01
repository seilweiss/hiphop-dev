#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct CutsceneAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::CSN);

        CutsceneAsset(Asset asset) : DefaultAsset(asset) {}
    };

}