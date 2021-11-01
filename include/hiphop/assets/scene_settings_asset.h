#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct SceneSettingsAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::SSET);

        SceneSettingsAsset(Asset asset) : DefaultAsset(asset) {}
    };

}