#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct SoundGroupAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::SGRP);

        SoundGroupAsset(Asset asset) : DefaultAsset(asset) {}
    };

}