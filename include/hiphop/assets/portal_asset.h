#pragma once

#include "hiphop/core/base_asset.h"

namespace HipHop {

    struct PortalAsset : BaseAsset
    {
        HIPHOP_ASSET(AssetType::PORT);

        PortalAsset(Asset asset) : BaseAsset(asset, BaseType::Portal) {}

        uint32_t assetCameraID = 0;
        uint32_t assetMarkerID = 0;
        float ang = 0.0f;
        uint32_t sceneID = 0;

        void Read(Stream* stream);
        void Write(Stream* stream);
    };

}