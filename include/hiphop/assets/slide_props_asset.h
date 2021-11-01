#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct SlidePropsAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::SLID);

        SlidePropsAsset(Asset asset) : DefaultAsset(asset) {}
    };

}