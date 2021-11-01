#include "hiphop/assets/dyna/bus_stop_asset.h"

namespace HipHop {

    namespace Dyna {

        void BusStopAsset::Read(Stream* stream)
        {
            DynaAsset::Read(stream);

            stream->Read(&marker);
            stream->Read(&character);
            stream->Read(&cameraID);
            stream->Read(&busID);
            stream->Read(&delay);

            ReadLinks(stream);
        }

        void BusStopAsset::Write(Stream* stream)
        {
            DynaAsset::Write(stream);

            stream->Write(&marker);
            stream->Write(&character);
            stream->Write(&cameraID);
            stream->Write(&busID);
            stream->Write(&delay);

            WriteLinks(stream);
        }
    }

}