#include "hiphop/assets/fog_asset.h"

namespace HipHop {

    void FogAsset::Read(Stream* stream)
    {
        BaseAsset::Read(stream);

        stream->Read(bkgndColor, sizeof(bkgndColor));
        stream->Read(fogColor, sizeof(fogColor));
        stream->Read(&fogDensity);
        stream->Read(&fogStart);
        stream->Read(&fogStop);
        stream->Read(&transitionTime);
        stream->Read(&fogType);
        stream->Align(4);

        ReadLinks(stream);
    }

    void FogAsset::Write(Stream* stream)
    {
        BaseAsset::Write(stream);

        stream->Write(bkgndColor, sizeof(bkgndColor));
        stream->Write(fogColor, sizeof(fogColor));
        stream->Write(&fogDensity);
        stream->Write(&fogStart);
        stream->Write(&fogStop);
        stream->Write(&transitionTime);
        stream->Write(&fogType);
        stream->Align(4);

        WriteLinks(stream);
    }

}