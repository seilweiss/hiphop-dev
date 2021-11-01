#include "hiphop/assets/dyna/teleport_asset.h"

namespace HipHop {

    namespace Dyna {

        void TeleportAsset::Read(Stream* stream)
        {
            DynaAsset::Read(stream);

            stream->Read(&marker);
            stream->Read(&opened);

            if (version > 1)
            {
                stream->Read(&launchAngle);
            }

            stream->Read(&camAngle);
            stream->Read(&targetID);

            ReadLinks(stream);
        }

        void TeleportAsset::Write(Stream* stream)
        {
            DynaAsset::Write(stream);

            stream->Write(&marker);
            stream->Write(&opened);

            if (version > 1)
            {
                stream->Write(&launchAngle);
            }

            stream->Write(&camAngle);
            stream->Write(&targetID);

            WriteLinks(stream);
        }

    }

}