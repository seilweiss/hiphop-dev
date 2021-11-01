#pragma once

#include "hiphop/core/ent_asset.h"

namespace HipHop {

    struct PlayerAsset : EntAsset
    {
        HIPHOP_ASSET(AssetType::PLYR);

        PlayerAsset(Asset asset) : EntAsset(asset, BaseType::Player)
        {
            baseFlags = BaseAsset::Enabled | BaseAsset::Valid | EntAsset::VisibleDuringCutscenes;
        }

        uint32_t lightKitID = 0;

        void Read(Stream* stream);
        void Write(Stream* stream);
    };

}