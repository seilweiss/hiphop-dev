#include "hiphop/core/asset_serializer.h"

#include "hiphop/core/memory_stream.h"
#include "hiphop/core/file.h"

namespace HipHop {

	void AssetSerializer::Load()
	{
		if (!m_asset)
		{
			return;
		}

		if (!m_asset.IsLoaded() && !m_asset.Load())
		{
			return;
		}

		const void* data = m_asset.GetData();
		size_t size = m_asset.GetSize();

		if (data && size > 0)
		{
			MemoryStream stream(data, size);
			stream.SetEndian(Util::GetPlatformEndian(m_asset.GetFile()->GetPlatform()));

			Read(&stream);
		}
	}

	void AssetSerializer::Save()
	{
		if (!m_asset)
		{
			return;
		}

		MemoryStream stream;
		stream.SetEndian(Util::GetPlatformEndian(m_asset.GetFile()->GetPlatform()));

		Write(&stream);

		if (stream.GetSize() > 0)
		{
			m_asset.SetData(stream.GetData(), (uint32_t)stream.GetSize());
		}
		else
		{
			m_asset.SetData(nullptr, 0);
		}
	}

}