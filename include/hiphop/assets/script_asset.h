#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct ScriptAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::SCRP);

        ScriptAsset(Asset asset) : DefaultAsset(asset) {}
    };

}