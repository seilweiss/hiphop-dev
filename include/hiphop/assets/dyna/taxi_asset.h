#pragma once

#include "hiphop/core/dyna_asset.h"

namespace HipHop {

    namespace Dyna {

        struct TaxiAsset : DynaAsset
        {
            HIPHOP_DYNAASSET("game_object:Taxi");

            TaxiAsset(Asset asset) : DynaAsset("game_object:Taxi", 1, asset) {}

            uint32_t marker = 0;
            uint32_t cameraID = 0;
            uint32_t portalID = 0;
            uint32_t talkBoxID = 0;
            uint32_t textID = 0;
            uint32_t taxiID = 0;
            float invDelay = 0.0f;
            float portalDelay = 0.0f;

            void Read(Stream* stream);
            void Write(Stream* stream);
        };

    }

}