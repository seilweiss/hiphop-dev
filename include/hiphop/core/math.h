#pragma once

namespace HipHop {

    struct Vec3
    {
        float x;
        float y;
        float z;

        Vec3() : x(0.0f), y(0.0f), z(0.0f) {}
        Vec3(float xyz) : x(xyz), y(xyz), z(xyz) {}
        Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

        void Read(Stream* stream)
        {
            stream->Read(&x);
            stream->Read(&y);
            stream->Read(&z);
        }

        void Write(Stream* stream)
        {
            stream->Write(&x);
            stream->Write(&y);
            stream->Write(&z);
        }
    };

    struct Quat
    {
        Vec3 v;
        float s;

        Quat() : v(), s(1.0f) {}
        Quat(const Vec3& v, float s) : v(v), s(s) {}

        void Read(Stream* stream)
        {
            v.Read(stream);
            stream->Read(&s);
        }

        void Write(Stream* stream)
        {
            v.Write(stream);
            stream->Write(&s);
        }
    };

    namespace Math {

        const float PI = 3.14159265f;

        inline float Deg2Rad(float x) { return x * (PI / 180.0f); }
        inline float Rad2Deg(float x) { return x * (180.0f / PI); }
        inline Vec3 Deg2Rad(const Vec3& v) { return { Deg2Rad(v.x), Deg2Rad(v.y), Deg2Rad(v.z) }; }
        inline Vec3 Rad2Deg(const Vec3& v) { return { Rad2Deg(v.x), Rad2Deg(v.y), Rad2Deg(v.z) }; }

    }

}