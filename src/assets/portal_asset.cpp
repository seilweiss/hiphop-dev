#include "hiphop/assets/portal_asset.h"

namespace HipHop {

    void PortalAsset::Read(Stream* stream)
    {
        BaseAsset::Read(stream);

        stream->Read(&assetCameraID);
        stream->Read(&assetMarkerID);
        stream->Read(&ang);
        stream->Read(&sceneID);

        ReadLinks(stream);
    }

    void PortalAsset::Write(Stream* stream)
    {
        BaseAsset::Write(stream);

        stream->Write(&assetCameraID);
        stream->Write(&assetMarkerID);
        stream->Write(&ang);
        stream->Write(&sceneID);

        WriteLinks(stream);
    }

}