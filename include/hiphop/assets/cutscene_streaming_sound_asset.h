#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct CutsceneStreamingSoundAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::CSSS);

        CutsceneStreamingSoundAsset(Asset asset) : DefaultAsset(asset) {}
    };

}