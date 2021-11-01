#include "hiphop/core/dyna_asset.h"

namespace HipHop {

    void DynaAsset::Read(Stream* stream)
    {
        BaseAsset::Read(stream);

        stream->Read(&type);
        stream->Read(&version);
        stream->Read(&handle);
    }

    void DynaAsset::Write(Stream* stream)
    {
        BaseAsset::Write(stream);

        stream->Write(&type);
        stream->Write(&version);
        stream->Write(&handle);
    }

}