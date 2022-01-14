#include "hiphop/assets/trigger_asset.h"

namespace HipHop {

	void TriggerAsset::Read(Stream* stream)
	{
		EntAsset::Read(stream);

		p[0].Read(stream);
		p[1].Read(stream);
		p[2].Read(stream);
		p[3].Read(stream);
		direction.Read(stream);
		stream->Read(&flags);

		ReadLinks(stream);
	}

	void TriggerAsset::Write(Stream* stream)
	{
		EntAsset::Write(stream);

		p[0].Write(stream);
		p[1].Write(stream);
		p[2].Write(stream);
		p[3].Write(stream);
		direction.Write(stream);
		stream->Write(&flags);

		WriteLinks(stream);
	}

}