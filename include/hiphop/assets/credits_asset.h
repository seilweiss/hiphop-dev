#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct CreditsAsset : AssetEditor
    {
        HIPHOP_ASSET(AssetType::CRDT);

        CreditsAsset(Asset asset) : AssetEditor(asset) {}
    };

}