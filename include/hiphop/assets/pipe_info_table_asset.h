#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct PipeInfoTableAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::PIPT);

        PipeInfoTableAsset(Asset asset) : DefaultAsset(asset) {}
    };

}