#pragma once

#include "hiphop/core/dyna_asset.h"

namespace HipHop {

    namespace Dyna {

        struct BusStopAsset : DynaAsset
        {
            HIPHOP_DYNAASSET("game_object:BusStop");

            BusStopAsset(Asset asset) : DynaAsset("game_object:BusStop", 2, asset) {}

            uint32_t marker = 0;
            uint32_t character = 0;
            uint32_t cameraID = 0;
            uint32_t busID = 0;
            float delay = 0.0f;

            void Read(Stream* stream);
            void Write(Stream* stream);
        };

    }

}