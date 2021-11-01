#pragma once

#include "hiphop/core/base_asset.h"

namespace HipHop {

    struct CounterAsset : BaseAsset
    {
        HIPHOP_ASSET(AssetType::CNTR);

        CounterAsset(Asset asset) : BaseAsset(asset, BaseType::Counter) {}

        int16_t count = 0;

        void Read(Stream* stream);
        void Write(Stream* stream);
    };

}