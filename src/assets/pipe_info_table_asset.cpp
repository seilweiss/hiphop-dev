#include "hiphop/assets/pipe_info_table_asset.h"

namespace HipHop {

	void PipeInfo::Read(Stream* stream)
	{
		stream->Read(&ModelHashID);
		stream->Read(&SubObjectBits);
		stream->Read(&PipeFlags);
	}

	void PipeInfo::Write(Stream* stream)
	{
		stream->Write(&ModelHashID);
		stream->Write(&SubObjectBits);
		stream->Write(&PipeFlags);
	}

	void PipeInfoTableAsset::Read(Stream* stream)
	{
		int32_t count;
		stream->Read(&count);

		pipeInfo.reserve(count);

		for (int32_t i = 0; i < count; i++)
		{
			PipeInfo info;
			info.Read(stream);
			pipeInfo.push_back(info);
		}
	}

	void PipeInfoTableAsset::Write(Stream* stream)
	{
		int32_t count = (int32_t)pipeInfo.size();
		stream->Write(&count);

		for (PipeInfo& info : pipeInfo)
		{
			info.Write(stream);
		}
	}

}