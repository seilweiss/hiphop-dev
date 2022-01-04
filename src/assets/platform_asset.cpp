#include "hiphop/assets/platform_asset.h"

namespace HipHop {

	void PlatformERData::Read(Stream*)
	{
	}

	void PlatformERData::Write(Stream*)
	{
	}

	void PlatformOrbitData::Read(Stream*)
	{
	}

	void PlatformOrbitData::Write(Stream*)
	{
	}

	void PlatformSplineData::Read(Stream*)
	{
	}

	void PlatformSplineData::Write(Stream*)
	{
	}

	void PlatformMPData::Read(Stream*)
	{
	}

	void PlatformMPData::Write(Stream*)
	{
	}

	void PlatformMechData::Read(Stream*)
	{
	}

	void PlatformMechData::Write(Stream*)
	{
	}

	void PlatformPenData::Read(Stream*)
	{
	}

	void PlatformPenData::Write(Stream*)
	{
	}

	void PlatformConvBeltData::Read(Stream* stream)
	{
		stream->Read(&speed);
	}

	void PlatformConvBeltData::Write(Stream* stream)
	{
		stream->Write(&speed);
	}

	void PlatformFallingData::Read(Stream* stream)
	{
		stream->Read(&speed);
		stream->Read(&bustModelID);
	}

	void PlatformFallingData::Write(Stream* stream)
	{
		stream->Write(&speed);
		stream->Write(&bustModelID);
	}

	void PlatformFRData::Read(Stream* stream)
	{
		stream->Read(&fspeed);
		stream->Read(&rspeed);
		stream->Read(&ret_delay);
		stream->Read(&post_ret_delay);
	}

	void PlatformFRData::Write(Stream* stream)
	{
		stream->Write(&fspeed);
		stream->Write(&rspeed);
		stream->Write(&ret_delay);
		stream->Write(&post_ret_delay);
	}

	void PlatformBreakawayData::Read(Stream* stream)
	{
		stream->Read(&ba_delay);
		stream->Read(&bustModelID);
		stream->Read(&reset_delay);
		stream->Read(&breakflags);
	}

	void PlatformBreakawayData::Write(Stream* stream)
	{
		stream->Write(&ba_delay);
		stream->Write(&bustModelID);
		stream->Write(&reset_delay);
		stream->Write(&breakflags);
	}

	void PlatformSpringboardData::Read(Stream* stream)
	{
		stream->Read(jmph, sizeof(jmph));
		stream->Read(&jmpbounce);
		stream->Read(animID, sizeof(animID));
		jmpdir.Read(stream);
		stream->Read(&springflags);
	}

	void PlatformSpringboardData::Write(Stream* stream)
	{
		stream->Write(jmph, sizeof(jmph));
		stream->Write(&jmpbounce);
		stream->Write(animID, sizeof(animID));
		jmpdir.Write(stream);
		stream->Write(&springflags);
	}

	void PlatformTeeterData::Read(Stream* stream)
	{
		stream->Read(&itilt);
		stream->Read(&maxtilt);
		stream->Read(&invmass);
	}

	void PlatformTeeterData::Write(Stream* stream)
	{
		stream->Write(&itilt);
		stream->Write(&maxtilt);
		stream->Write(&invmass);
	}

	void PlatformPaddleData::Read(Stream* stream)
	{
		stream->Read(&startOrient);
		stream->Read(&countOrient);
		stream->Read(&orientLoop);
		stream->Read(orient, sizeof(orient));
		stream->Read(&paddleFlags);
		stream->Read(&rotateSpeed);
		stream->Read(&accelTime);
		stream->Read(&decelTime);
		stream->Read(&hubRadius);
	}

	void PlatformPaddleData::Write(Stream* stream)
	{
		stream->Write(&startOrient);
		stream->Write(&countOrient);
		stream->Write(&orientLoop);
		stream->Write(orient, sizeof(orient));
		stream->Write(&paddleFlags);
		stream->Write(&rotateSpeed);
		stream->Write(&accelTime);
		stream->Write(&decelTime);
		stream->Write(&hubRadius);
	}

	void PlatformFMData::Read(Stream*)
	{
	}

	void PlatformFMData::Write(Stream*)
	{
	}

	void PlatformAsset::Read(Stream* stream)
	{
		EntAsset::Read(stream);

		stream->Read(&type);
		stream->Skip(1);
		stream->Read(&flags);

		size_t end = stream->Tell() + 0x38;

		switch (type)
		{
		case ExtendRetract: er.Read(stream); break;
		case Orbit: orb.Read(stream); break;
		case Spline: spl.Read(stream); break;
		case MovePoint: mp.Read(stream); break;
		case Mechanism: mech.Read(stream); break;
		case Pendulum: pen.Read(stream); break;
		case ConveyorBelt: cb.Read(stream); break;
		case Falling: fall.Read(stream); break;
		case ForwardReturn: fr.Read(stream); break;
		case Breakaway: ba.Read(stream); break;
		case Springboard: sb.Read(stream); break;
		case TeeterTotter: teet.Read(stream); break;
		case Paddle: paddle.Read(stream); break;
		case FullyManipulable: fm.Read(stream); break;
		}

		stream->Seek(end);

		motion.Read(stream, GetAsset());

		ReadLinks(stream);
	}

	void PlatformAsset::Write(Stream* stream)
	{
		EntAsset::Write(stream);

		stream->Write(&type);
		stream->Write(&flags);

		size_t end = stream->Tell() + 0x38;

		switch (type)
		{
		case ExtendRetract: er.Write(stream); break;
		case Orbit: orb.Write(stream); break;
		case Spline: spl.Write(stream); break;
		case MovePoint: mp.Write(stream); break;
		case Mechanism: mech.Write(stream); break;
		case Pendulum: pen.Write(stream); break;
		case ConveyorBelt: cb.Write(stream); break;
		case Falling: fall.Write(stream); break;
		case ForwardReturn: fr.Write(stream); break;
		case Breakaway: ba.Write(stream); break;
		case Springboard: sb.Write(stream); break;
		case TeeterTotter: teet.Write(stream); break;
		case Paddle: paddle.Write(stream); break;
		case FullyManipulable: fm.Write(stream); break;
		}

		stream->Seek(end);

		motion.Write(stream, GetAsset());

		WriteLinks(stream);
	}

}