#include "hiphop/core/link_asset.h"

namespace HipHop {

    void LinkAsset::Read(Stream* stream)
    {
        stream->Read(&srcEvent);
        stream->Read(&dstEvent);
        stream->Read(&dstAssetID);

        for (int i = 0; i < 4; i++)
        {
            stream->Read(&param[i].i);
        }

        stream->Read(&paramWidgetAssetID);
        stream->Read(&chkAssetID);
    }

    void LinkAsset::Write(Stream* stream)
    {
        stream->Write(&srcEvent);
        stream->Write(&dstEvent);
        stream->Write(&dstAssetID);

        for (int i = 0; i < 4; i++)
        {
            stream->Write(&param[i].i);
        }

        stream->Write(&paramWidgetAssetID);
        stream->Write(&chkAssetID);
    }

}