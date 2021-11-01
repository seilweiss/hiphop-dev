#pragma once

#include "hiphop/core/base_asset.h"

namespace HipHop {

    struct DispatcherAsset : BaseAsset
    {
        HIPHOP_ASSET(AssetType::DPAT);

        DispatcherAsset(Asset asset) : BaseAsset(asset, BaseType::Dispatcher) {}

        void Read(Stream* stream);
        void Write(Stream* stream);
    };

}