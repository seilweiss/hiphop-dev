#pragma once

#include "hiphop/core/base_asset.h"
#include "hiphop/core/math.h"

namespace HipHop {

    struct CamAsset : BaseAsset
    {
        HIPHOP_ASSET(AssetType::CAM);

        enum Type
        {
            Follow,
            Shoulder,
            Static,
            Path,
            StaticFollow
        };

        enum TransType
        {
            None,
            Interp1,
            Interp2,
            Interp3,
            Interp4,
            Linear,
            Interp1Rev,
            Interp2Rev,
            Interp3Rev,
            Interp4Rev,
            Total
        };

        struct FollowAsset
        {
            float rotation = 0.0f;
            float distance = 0.0f;
            float height = 0.0f;
            float rubber_band = 0.0f;
            float start_speed = 0.0f;
            float end_speed = 0.0f;
        };

        struct ShoulderAsset
        {
            float distance = 0.0f;
            float height = 0.0f;
            float realign_speed = 0.0f;
            float realign_delay = 0.0f;
        };

        struct StaticAsset
        {
            uint32_t unused = 0;
        };

        struct PathAsset
        {
            uint32_t assetID = 0;
            float time_end = 0.0f;
            float time_delay = 0.0f;
        };

        struct StaticFollowAsset
        {
            float rubber_band = 0.0f;
        };

        CamAsset(Asset asset) : BaseAsset(asset, BaseType::Camera) {}

        Vec3 pos;
        Vec3 at;
        Vec3 up;
        Vec3 right;
        Vec3 view_offset;
        int16_t offset_start_frames = 30;
        int16_t offset_end_frames = 45;
        float fov = 85.0f;
        float trans_time = 0.0f;
        TransType trans_type = None;
        uint32_t flags = 0;
        float fade_up = 0.0f;
        float fade_down = 0.0f;

        union
        {
            FollowAsset cam_follow;
            ShoulderAsset cam_shoulder;
            StaticAsset cam_static;
            PathAsset cam_path;
            StaticFollowAsset cam_staticFollow;
        };

        uint32_t valid_flags = 0x000101C0;
        uint32_t markerid[2] = {};
        uint8_t cam_type = Static;

        void Read(Stream* stream);
        void Write(Stream* stream);
    };

}