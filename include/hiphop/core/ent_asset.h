#pragma once

#include "hiphop/core/base_asset.h"
#include "hiphop/core/math.h"

namespace HipHop {

    struct EntAsset : BaseAsset
    {
        enum EntBaseFlags
        {
            VisibleDuringCutscenes = 0x8,
            ReceiveShadows = 0x10
        };

        enum EntFlags
        {
            Visible = 0x1,
            Stackable = 0x2
        };

        enum EntMoreFlags
        {
            PreciseCollision = 0x2,
            Hittable = 0x10,
            AnimateCollision = 0x20,
            LedgeGrab = 0x80
        };

        EntAsset(Asset asset, BaseType baseType = BaseType::Unknown) : BaseAsset(asset, baseType)
        {
            baseFlags |= VisibleDuringCutscenes | ReceiveShadows;
        }

        uint8_t flags = Visible;
        uint8_t subtype = 0;
        uint8_t pflags = 0;
        uint8_t moreFlags = PreciseCollision;
        uint32_t surfaceID = 0;
        Vec3 ang = { 0.0f, 0.0f, 0.0f };
        Vec3 pos = { 0.0f, 0.0f, 0.0f };
        Vec3 scale = { 1.0f, 1.0f, 1.0f };
        float redMult = 1.0f;
        float greenMult = 1.0f;
        float blueMult = 1.0f;
        float seeThru = 1.0f;
        float seeThruSpeed = 255.0f;
        uint32_t modelInfoID = 0;
        uint32_t animListID = 0;

        virtual void Read(Stream* stream);
        virtual void Write(Stream* stream);
    };

}