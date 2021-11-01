#include "hiphop/core/ent_asset.h"

#include "hiphop/core/file.h"

namespace HipHop {

    void EntAsset::Read(Stream* stream)
    {
        BaseAsset::Read(stream);

        stream->Read(&flags);
        stream->Read(&subtype);
        stream->Read(&pflags);
        stream->Read(&moreFlags);

        if (GetAsset().GetFile()->DoEntAssetsHavePad())
        {
            uint32_t pad;
            stream->Read(&pad);
        }

        stream->Read(&surfaceID);
        ang.Read(stream);
        pos.Read(stream);
        scale.Read(stream);
        stream->Read(&redMult);
        stream->Read(&greenMult);
        stream->Read(&blueMult);
        stream->Read(&seeThru);
        stream->Read(&seeThruSpeed);
        stream->Read(&modelInfoID);
        stream->Read(&animListID);
    }

    void EntAsset::Write(Stream* stream)
    {
        BaseAsset::Write(stream);

        stream->Write(&flags);
        stream->Write(&subtype);
        stream->Write(&pflags);
        stream->Write(&moreFlags);

        if (GetAsset().GetFile()->DoEntAssetsHavePad())
        {
            uint32_t pad = 0;
            stream->Write(&pad);
        }

        stream->Write(&surfaceID);
        ang.Write(stream);
        pos.Write(stream);
        scale.Write(stream);
        stream->Write(&redMult);
        stream->Write(&greenMult);
        stream->Write(&blueMult);
        stream->Write(&seeThru);
        stream->Write(&seeThruSpeed);
        stream->Write(&modelInfoID);
        stream->Write(&animListID);
    }

}