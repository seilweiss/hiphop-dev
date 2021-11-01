#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct NPCSettingsAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::NPCS);

        NPCSettingsAsset(Asset asset) : DefaultAsset(asset) {}
    };

}