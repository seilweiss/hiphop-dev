#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

    struct CameraCurveAsset : DefaultAsset
    {
        HIPHOP_ASSET(AssetType::CCRV);

        CameraCurveAsset(Asset asset) : DefaultAsset(asset) {}
    };

}