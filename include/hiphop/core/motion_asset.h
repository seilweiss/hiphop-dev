#pragma once

#include "hiphop/core/asset.h"
#include "hiphop/core/stream.h"
#include "hiphop/core/math.h"

namespace HipHop {

    struct MotionERData
    {
        Vec3 ret_pos;
        Vec3 ext_dpos;
        float ext_tm = 0.0f;
        float ext_wait_tm = 0.0f;
        float ret_tm = 0.0f;
        float ret_wait_tm = 0.0f;
    };

    struct MotionOrbitData
    {
        Vec3 center;
        float w = 0.0f;
        float h = 0.0f;
        float period = 0.0f;
    };

    struct MotionSplineData
    {
        int32_t unknown = 0; // BFBB only
        uint32_t spline_id = 0; // not in BFBB
        float speed = 0.0f; // not in BFBB
        float lean_modifier = 0.0f; // not in BFBB
    };

    struct MotionMPData
    {
        uint32_t flags = 0;
        uint32_t mp_id = 0;
        float speed = 0.0f;
    };

    struct MotionMechData
    {
        enum Type
        {
            Slide = 0,
            Rotate = 1,
            SlideAndRotate = 2,
            SlideThenRotate = 3,
            RotateThenSlide = 4
        };

        enum Flags
        {
            ReturnToStart = 0x1,
            DontLoop = 0x2
        };

        enum Axis
        {
            X = 0,
            Y = 1,
            Z = 2
        };

        uint8_t type = Slide;
        uint8_t flags = 0;
        uint8_t sld_axis = X;
        uint8_t rot_axis = X;
        uint8_t scale_axis = X; // not in BFBB
        float sld_dist = 0.0f;
        float sld_tm = 0.0f;
        float sld_acc_tm = 0.0f;
        float sld_dec_tm = 0.0f;
        float rot_dist = 0.0f;
        float rot_tm = 0.0f;
        float rot_acc_tm = 0.0f;
        float rot_dec_tm = 0.0f;
        float ret_delay = 0.0f;
        float post_ret_delay = 0.0f;
        float scale_amount = 0.0f; // not in BFBB
        float scale_duration = 0.0f; // not in BFBB
    };

    struct MotionPenData
    {
        uint8_t flags = 0;
        uint8_t plane = 0;
        float len = 0.0f;
        float range = 0.0f;
        float period = 0.0f;
        float phase = 0.0f;
    };

    struct MotionAsset
    {
        enum Type
        {
            ExtendRetract,
            Orbit,
            Spline,
            MovePoint,
            Mechanism,
            Pendulum,
            None
        };

        enum Flags
        {
            Stopped = 0x4
        };

        uint8_t type = None;
        bool use_banking = false;
        uint16_t flags = Stopped;
        MotionERData er;
        MotionOrbitData orb;
        MotionSplineData spl;
        MotionMPData mp;
        MotionMechData mech;
        MotionPenData pen;

        void Read(Stream* stream, Asset asset);
        void Write(Stream* stream, Asset asset);
    };

}