#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct DashTrackAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::DTRK);

        DashTrackAsset(Asset asset) : DefaultAsset(asset) {}
    };

}