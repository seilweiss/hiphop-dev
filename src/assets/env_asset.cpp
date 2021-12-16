#include "hiphop/assets/env_asset.h"

#include "hiphop/core/file.h"

namespace HipHop {

    void EnvAsset::Read(Stream* stream)
    {
        BaseAsset::Read(stream);

        stream->Read(&bspAssetID);
        stream->Read(&startCameraAssetID);
        stream->Read(&climateFlags);
        stream->Read(&climateStrengthMin);
        stream->Read(&climateStrengthMax);
        stream->Read(&bspLightKit);
        stream->Read(&objectLightKit);
        stream->Read(&flags);
        stream->Read(&bspCollisionAssetID);
        stream->Read(&bspFXAssetID);
        stream->Read(&bspCameraAssetID);
        stream->Read(&bspMapperID);
        stream->Read(&bspMapperCollisionID);
        stream->Read(&bspMapperFXID);

        if (GetFile()->GetGame() >= Game::BattleForBikiniBottom)
        {
            Endian oldEndian = stream->GetEndian();

            stream->SetEndian(Endian::Little);
            stream->Read(&loldHeight);
            stream->SetEndian(oldEndian);

            if (GetFile()->GetGame() >= Game::SpongeBobMovie)
            {
                minBounds.Read(stream);
                maxBounds.Read(stream);
            }
        }

        ReadLinks(stream);
    }

    void EnvAsset::Write(Stream* stream)
    {
        BaseAsset::Write(stream);

        stream->Write(&bspAssetID);
        stream->Write(&startCameraAssetID);
        stream->Write(&climateFlags);
        stream->Write(&climateStrengthMin);
        stream->Write(&climateStrengthMax);
        stream->Write(&bspLightKit);
        stream->Write(&objectLightKit);
        stream->Write(&flags);
        stream->Write(&bspCollisionAssetID);
        stream->Write(&bspFXAssetID);
        stream->Write(&bspCameraAssetID);
        stream->Write(&bspMapperID);
        stream->Write(&bspMapperCollisionID);
        stream->Write(&bspMapperFXID);

        if (GetFile()->GetGame() >= Game::BattleForBikiniBottom)
        {
            Endian oldEndian = stream->GetEndian();

            stream->SetEndian(Endian::Little);
            stream->Write(&loldHeight);
            stream->SetEndian(oldEndian);

            if (GetFile()->GetGame() >= Game::SpongeBobMovie)
            {
                minBounds.Write(stream);
                maxBounds.Write(stream);
            }
        }

        WriteLinks(stream);
    }

}