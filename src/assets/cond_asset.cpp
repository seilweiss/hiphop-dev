#include "hiphop/assets/cond_asset.h"

namespace HipHop {

    void CondAsset::Read(Stream* stream)
    {
        BaseAsset::Read(stream);

        stream->Read(&constNum);
        stream->Read(&expr1);
        stream->Read(&op);
        stream->Read(&value_asset);

        ReadLinks(stream);
    }

    void CondAsset::Write(Stream* stream)
    {
        BaseAsset::Write(stream);

        stream->Write(&constNum);
        stream->Write(&expr1);
        stream->Write(&op);
        stream->Write(&value_asset);

        WriteLinks(stream);
    }

}