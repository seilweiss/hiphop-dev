#pragma once

#include "hiphop/core/dyna_asset.h"
#include "hiphop/core/math.h"

namespace HipHop {

    namespace Dyna {

        struct PointerAsset : DynaAsset
        {
            HIPHOP_DYNAASSET("pointer");

            PointerAsset(Asset asset) : DynaAsset("pointer", 1, asset) {}

            Vec3 loc;
            float yaw = 0.0f;
            float pitch = 0.0f;
            float roll = 0.0f;

            void Read(Stream* stream);
            void Write(Stream* stream);
        };

    }

}