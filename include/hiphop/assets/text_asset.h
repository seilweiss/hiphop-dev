#pragma once

#include "hiphop/core/asset_editor.h"

namespace HipHop {

    struct TextAsset : AssetEditor
    {
        HIPHOP_ASSET(AssetType::TEXT);

        TextAsset(Asset asset) : AssetEditor(asset) {}

        std::string text;

        void Read(Stream* stream);
        void Write(Stream* stream);
    };

}