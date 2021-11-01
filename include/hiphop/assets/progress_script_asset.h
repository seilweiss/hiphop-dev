#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct ProgressScriptAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::PGRS);

        ProgressScriptAsset(Asset asset) : DefaultAsset(asset) {}
    };

}