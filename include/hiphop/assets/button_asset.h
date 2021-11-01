#pragma once

#include "hiphop/core/ent_asset.h"
#include "hiphop/core/motion_asset.h"

namespace HipHop {

    struct ButtonAsset : EntAsset
    {
        HIPHOP_ASSET(AssetType::BUTN);

        enum ActMethod
        {
            Button = 0,
            PressurePlate = 1
        };

        enum ActFlags
        {
            SBMelee = 0x1,
            SBBubbleBounce = 0x2,
            SBBubbleBash = 0x4,
            SBBubbleBowl = 0x8,
            SBCruiseBubble = 0x10,
            SBBungee = 0x20,
            PatThrowNPC = 0x40,
            PatThrowFruit = 0x80,
            PatSlam = 0x100,
            PressurePlatePlayer = 0x400,
            PressurePlateNPC = 0x800,
            PressurePlateSBBubbleBowl = 0x1000,
            PressurePlatePatStoneTiki = 0x2000,
            SandyMelee = 0x4000,
            PatMelee = 0x8000,
            PressurePlatePatThrowFruit = 0x10000,
            PatCartwheel = 0x20000
        };

        ButtonAsset(Asset asset) : EntAsset(asset, BaseType::Button) {}

        uint32_t modelPressedInfoID = 0;
        uint32_t actMethod = Button;
        int32_t initButtonState = 0;
        int32_t isReset = 0;
        float resetDelay = 1.5f;
        uint32_t buttonActFlags = SBMelee | SBBubbleBounce | SBBubbleBash | SBBubbleBowl | SBCruiseBubble | SBBungee | PatThrowNPC | PatThrowFruit | PatSlam | SandyMelee | PatMelee;
        MotionAsset motion;

        void Init(ActMethod actMethod);

        void Read(Stream* stream);
        void Write(Stream* stream);
    };

}