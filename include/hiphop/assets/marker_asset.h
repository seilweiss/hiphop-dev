#pragma once

#include "hiphop/core/asset_editor.h"
#include "hiphop/core/math.h"

namespace HipHop {

    struct MarkerAsset : AssetEditor
    {
        HIPHOP_ASSET(AssetType::MRKR);

        MarkerAsset(Asset asset) : AssetEditor(asset) {}

        Vec3 pos;

        void Read(Stream* stream);
        void Write(Stream* stream);
    };

}