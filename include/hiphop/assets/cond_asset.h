#pragma once

#include "hiphop/core/base_asset.h"

namespace HipHop {

    struct CondAsset : BaseAsset
    {
        HIPHOP_ASSET(AssetType::COND);

        enum Operation
        {
            EqualTo = 0,
            GreaterThan = 1,
            LessThan = 2,
            GreaterThanOrEquals = 3,
            LessThanOrEqualTo = 4,
            NotEqualTo = 5
        };

        CondAsset(Asset asset) : BaseAsset(asset, BaseType::Cond) {}

        uint32_t constNum = 0;
        uint32_t expr1 = 0;
        uint32_t op = EqualTo;
        uint32_t value_asset = 0;

        void Read(Stream* stream);
        void Write(Stream* stream);
    };

}