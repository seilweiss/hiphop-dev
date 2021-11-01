#pragma once

#include "hiphop/core/dyna_asset.h"

namespace HipHop {

    namespace Dyna {

        struct TeleportAsset : DynaAsset
        {
            HIPHOP_DYNAASSET("game_object:Teleport");

            TeleportAsset(Asset asset) : DynaAsset("game_object:Teleport", 2, asset) {}

            uint32_t marker = 0;
            uint32_t opened = 0;
            uint32_t launchAngle = 0; // Not present in Version 1
            uint32_t camAngle = 0;
            uint32_t targetID = 0;

            void Read(Stream* stream);
            void Write(Stream* stream);
        };

    }

}