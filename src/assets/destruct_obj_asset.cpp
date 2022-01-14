#include "hiphop/assets/destruct_obj_asset.h"

#include "hiphop/core/file.h"

namespace HipHop {

	void DestructObjAsset::Read(Stream* stream)
	{
		EntAsset::Read(stream);

		stream->Read(&animSpeed);
		stream->Read(&initAnimState);
		stream->Read(&health);
		stream->Read(&spawnItemID);
		stream->Read(&dflags);
		stream->Read(&collType);
		stream->Read(&fxType);
		stream->Skip(2);
		stream->Read(&blast_radius);
		stream->Read(&blast_strength);

		if (GetFile()->GetGame() >= Game::BattleForBikiniBottom)
		{
			stream->Read(&shrapnelID_destroy);
			stream->Read(&shrapnelID_hit);
			stream->Read(&sfx_destroy);
			stream->Read(&sfx_hit);
			stream->Read(&hitModel);
			stream->Read(&destroyModel);
		}

		ReadLinks(stream);
	}

	void DestructObjAsset::Write(Stream* stream)
	{
		EntAsset::Write(stream);

		stream->Write(&animSpeed);
		stream->Write(&initAnimState);
		stream->Write(&health);
		stream->Write(&spawnItemID);
		stream->Write(&dflags);
		stream->Write(&collType);
		stream->Write(&fxType);
		stream->Skip(2);
		stream->Write(&blast_radius);
		stream->Write(&blast_strength);

		if (GetFile()->GetGame() >= Game::BattleForBikiniBottom)
		{
			stream->Write(&shrapnelID_destroy);
			stream->Write(&shrapnelID_hit);
			stream->Write(&sfx_destroy);
			stream->Write(&sfx_hit);
			stream->Write(&hitModel);
			stream->Write(&destroyModel);
		}

		WriteLinks(stream);
	}

}