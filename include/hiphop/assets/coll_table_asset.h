#pragma once

#include "hiphop/core/asset_editor.h"

#include <vector>

namespace HipHop {

    struct CollTableAsset : AssetEditor
    {
        HIPHOP_ASSET(AssetType::COLL);

        CollTableAsset(Asset asset) : AssetEditor(asset) {}

        struct Entry
        {
            uint32_t baseModel;
            uint32_t colModel;
            uint32_t camcolModel;
        };

        std::vector<Entry> entries;

        void Read(Stream* stream);
        void Write(Stream* stream);
    };

}