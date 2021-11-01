#pragma once

#include "hiphop/core/asset_editor.h"

namespace HipHop {

    struct AnimListAsset : AssetEditor
    {
        HIPHOP_ASSET(AssetType::ALST);

        AnimListAsset(Asset asset) : AssetEditor(asset) {}

        uint32_t ids[10] = {};

        void Read(Stream* stream);
        void Write(Stream* stream);
    };

}