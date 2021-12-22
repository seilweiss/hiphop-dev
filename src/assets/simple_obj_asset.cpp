#include "hiphop/assets/simple_obj_asset.h"

namespace HipHop {

    void SimpleObjAsset::Read(Stream* stream)
    {
        EntAsset::Read(stream);

        stream->Read(&animSpeed);
        stream->Read(&initAnimState);
        stream->Read(&collType);
        stream->Read(&flags);
        stream->Align(4);

        ReadLinks(stream);
    }

    void SimpleObjAsset::Write(Stream* stream)
    {
        EntAsset::Write(stream);

        stream->Write(&animSpeed);
        stream->Write(&initAnimState);
        stream->Write(&collType);
        stream->Write(&flags);
        stream->Align(4);

        WriteLinks(stream);
    }

}