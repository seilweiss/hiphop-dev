#pragma once

#include "hiphop/core/base_asset.h"

#include <vector>

namespace HipHop {

    struct GroupAsset : BaseAsset
    {
        HIPHOP_ASSET(AssetType::GRUP);

        GroupAsset(Asset asset) : BaseAsset(asset, BaseType::Group) {}

        uint16_t itemCount;
        uint16_t groupFlags;
        std::vector<uint32_t> items;

        void Read(Stream* stream);
        void Write(Stream* stream);
    };

}