#include "hiphop/assets/egen_asset.h"

namespace HipHop {

	void EGenAsset::Read(Stream* stream)
	{
		EntAsset::Read(stream);

		src_dpos.Read(stream);
		stream->Read(&damage_type);
		stream->Read(&flags);
		stream->Skip(2);
		stream->Read(&ontime);
		stream->Read(&onAnimID);

		ReadLinks(stream);
	}

	void EGenAsset::Write(Stream* stream)
	{
		EntAsset::Write(stream);

		src_dpos.Write(stream);
		stream->Write(&damage_type);
		stream->Write(&flags);
		stream->Skip(2);
		stream->Write(&ontime);
		stream->Write(&onAnimID);

		WriteLinks(stream);
	}

}