#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct LobMasterAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::LOBM);

        LobMasterAsset(Asset asset) : DefaultAsset(asset) {}
    };

}