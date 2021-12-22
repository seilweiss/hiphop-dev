#pragma once

#include "hiphop/core/ent_asset.h"

namespace HipHop {

    struct SimpleObjAsset : EntAsset
    {
        HIPHOP_ASSET(AssetType::SIMP);

        enum CollType
        {
            None = 0x0,
            Trigger = 0x1,
            Static = 0x2,
            Dynamic = 0x4,
            NPC = 0x8,
            Player = 0x10
        };

        SimpleObjAsset(Asset asset) : EntAsset(asset, BaseType::Static) {}

        float animSpeed;
        uint32_t initAnimState;
        uint8_t collType;
        uint8_t flags;

        void Read(Stream* stream);
        void Write(Stream* stream);
    };

}