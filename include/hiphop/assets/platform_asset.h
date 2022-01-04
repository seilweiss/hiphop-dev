#pragma once

#include "hiphop/core/ent_asset.h"
#include "hiphop/core/motion_asset.h"

namespace HipHop {

	struct PlatformERData
	{
		void Read(Stream* stream);
		void Write(Stream* stream);
	};

	struct PlatformOrbitData
	{
		void Read(Stream* stream);
		void Write(Stream* stream);
	};

	struct PlatformSplineData
	{
		void Read(Stream* stream);
		void Write(Stream* stream);
	};

	struct PlatformMPData
	{
		void Read(Stream* stream);
		void Write(Stream* stream);
	};

	struct PlatformMechData
	{
		void Read(Stream* stream);
		void Write(Stream* stream);
	};

	struct PlatformPenData
	{
		void Read(Stream* stream);
		void Write(Stream* stream);
	};

	struct PlatformConvBeltData
	{
		float speed = 0.0f;

		void Read(Stream* stream);
		void Write(Stream* stream);
	};

	struct PlatformFallingData
	{
		float speed = 0.0f;
		uint32_t bustModelID = 0;

		void Read(Stream* stream);
		void Write(Stream* stream);
	};

	struct PlatformFRData
	{
		float fspeed = 0.0f;
		float rspeed = 0.0f;
		float ret_delay = 0.0f;
		float post_ret_delay = 0.0f;

		void Read(Stream* stream);
		void Write(Stream* stream);
	};

	struct PlatformBreakawayData
	{
		enum Flags
		{
			AllowSneak = 0x1
		};

		float ba_delay = 0.0f;
		uint32_t bustModelID = 0;
		float reset_delay = 0.0f;
		uint32_t breakflags = 0;

		void Read(Stream* stream);
		void Write(Stream* stream);
	};

	struct PlatformSpringboardData
	{
		enum Flags
		{
			LockView = 0x1,
			LockMovement = 0x4
		};

		float jmph[3] = {};
		float jmpbounce = 0.0f;
		uint32_t animID[3] = {};
		Vec3 jmpdir = {};
		uint32_t springflags = 0;

		void Read(Stream* stream);
		void Write(Stream* stream);
	};

	struct PlatformTeeterData
	{
		float itilt = 0.0f;
		float maxtilt = 0.0f;
		float invmass = 0.0f;

		void Read(Stream* stream);
		void Write(Stream* stream);
	};

	struct PlatformPaddleData
	{
		int32_t startOrient = 0;
		int32_t countOrient = 0;
		float orientLoop = 0.0f;
		float orient[6] = {};
		uint32_t paddleFlags = 0;
		float rotateSpeed = 0.0f;
		float accelTime = 0.0f;
		float decelTime = 0.0f;
		float hubRadius = 0.0f;

		void Read(Stream* stream);
		void Write(Stream* stream);
	};

	struct PlatformFMData
	{
		void Read(Stream* stream);
		void Write(Stream* stream);
	};

	struct PlatformAsset : EntAsset
	{
		HIPHOP_ASSET(AssetType::PLAT);

		enum Type
		{
			Platform = 0,
			ExtendRetract = 0,
			Orbit,
			Spline,
			MovePoint,
			Mechanism,
			Pendulum,
			ConveyorBelt,
			Falling,
			ForwardReturn,
			Breakaway,
			Springboard,
			TeeterTotter,
			Paddle,
			FullyManipulable,
			Count
		};

		enum Flags
		{
			Shake = 0x1,
			Solid = 0x4
		};

		PlatformAsset(Asset asset) : EntAsset(asset, BaseType::Platform) {}

		uint8_t type = ExtendRetract;
		uint16_t flags = Shake;
		PlatformERData er;
		PlatformOrbitData orb;
		PlatformSplineData spl;
		PlatformMPData mp;
		PlatformMechData mech;
		PlatformPenData pen;
		PlatformConvBeltData cb;
		PlatformFallingData fall;
		PlatformFRData fr;
		PlatformBreakawayData ba;
		PlatformSpringboardData sb;
		PlatformTeeterData teet;
		PlatformPaddleData paddle;
		PlatformFMData fm;
		MotionAsset motion;

		void Read(Stream* stream);
		void Write(Stream* stream);
	};

}