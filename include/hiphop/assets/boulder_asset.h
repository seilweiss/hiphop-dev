#pragma once

#include "hiphop/core/ent_asset.h"

namespace HipHop {

    struct BoulderAsset : EntAsset
    {
        HIPHOP_ASSET(AssetType::BOUL);

        enum BoulderFlags
        {
            CanHitWalls = 0x1,
            DamagePlayer = 0x2,
            DamageNPCs = 0x8,
            DieOnOOBSurfs = 0x20,
            DieOnPlayerHit = 0x100,
            DieOnKillTimer = 0x200
        };

        BoulderAsset(Asset asset) : EntAsset(asset, BaseType::Boulder) {}

        float gravity = 10.0f;
        float mass = 1.0f;
        float bounce = 0.2f;
        float friction = 0.15f;
        float statFric = 0.0f; // BFBB only
        float maxVel = 40.0f;
        float maxAngVel = Math::Deg2Rad(1080.0f);
        float stickiness = 0.15f;
        float bounceDamp = 0.0f;
        uint32_t flags = DamagePlayer | 0x4 | DamageNPCs | DieOnOOBSurfs | DieOnKillTimer;
        float killtimer = 10.0f;
        uint32_t hitpoints = 1;
        uint32_t soundID = 0;
        float volume = 15.0f; // BFBB only
        float minSoundVel = 2.0f;
        float maxSoundVel = 7.5f;
        float innerRadius = 5.0f; // BFBB only
        float outerRadius = 20.0f; // BFBB only
        float fSphereRadius = 1.0f; // not in BFBB
        uint8_t uBoneIndex = 0; // not in BFBB

        void Read(Stream* stream);
        void Write(Stream* stream);
    };

}