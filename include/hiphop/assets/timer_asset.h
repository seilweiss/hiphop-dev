#pragma once

#include "hiphop/core/base_asset.h"

namespace HipHop {

    struct TimerAsset : BaseAsset
    {
        HIPHOP_ASSET(AssetType::TIMR);

        TimerAsset(Asset asset) : BaseAsset(asset, BaseType::Timer) {}

        float seconds = 0.0f;
        float randomRange = 0.0f;

        void Read(Stream* stream);
        void Write(Stream* stream);
    };

}