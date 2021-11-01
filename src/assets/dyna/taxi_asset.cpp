#include "hiphop/assets/dyna/taxi_asset.h"

namespace HipHop {

    namespace Dyna {

        void TaxiAsset::Read(Stream* stream)
        {
            DynaAsset::Read(stream);

            stream->Read(&marker);
            stream->Read(&cameraID);
            stream->Read(&portalID);
            stream->Read(&talkBoxID);
            stream->Read(&textID);
            stream->Read(&taxiID);
            stream->Read(&invDelay);
            stream->Read(&portalDelay);

            ReadLinks(stream);
        }

        void TaxiAsset::Write(Stream* stream)
        {
            DynaAsset::Write(stream);

            stream->Write(&marker);
            stream->Write(&cameraID);
            stream->Write(&portalID);
            stream->Write(&talkBoxID);
            stream->Write(&textID);
            stream->Write(&taxiID);
            stream->Write(&invDelay);
            stream->Write(&portalDelay);

            WriteLinks(stream);
        }

    }

}