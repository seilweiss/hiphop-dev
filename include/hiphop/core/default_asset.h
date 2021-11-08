#pragma once

#include "hiphop/core/asset_editor.h"

namespace HipHop {

    struct DefaultAsset : AssetEditor
    {
        DefaultAsset(Asset asset) : AssetEditor(asset) {}

        void Read(Stream*) {}
        void Write(Stream* stream) { stream->Write(GetData(), GetSize()); }

        const void* GetData() const { return GetAsset().GetData(); }
        uint32_t GetSize() const { return GetAsset().GetSize(); }
        void SetData(const void* data, uint32_t size) { GetAsset().SetData(data, size); }
    };

}
