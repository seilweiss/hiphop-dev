#include "hiphop/assets/player_asset.h"

namespace HipHop {

    void PlayerAsset::Read(Stream* stream)
    {
        EntAsset::Read(stream);

        ReadLinks(stream);

        stream->Read(&lightKitID);
    }

    void PlayerAsset::Write(Stream* stream)
    {
        EntAsset::Write(stream);

        WriteLinks(stream);

        stream->Write(&lightKitID);
    }

}