#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct ParSysAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::PARS);

        ParSysAsset(Asset asset) : DefaultAsset(asset) {}
    };

}