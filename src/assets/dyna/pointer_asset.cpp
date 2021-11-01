#include "hiphop/assets/dyna/pointer_asset.h"

namespace HipHop {

    namespace Dyna {

        void PointerAsset::Read(Stream* stream)
        {
            DynaAsset::Read(stream);

            loc.Read(stream);
            stream->Read(&yaw);
            stream->Read(&pitch);
            stream->Read(&roll);

            ReadLinks(stream);
        }

        void PointerAsset::Write(Stream* stream)
        {
            DynaAsset::Write(stream);

            loc.Write(stream);
            stream->Write(&yaw);
            stream->Write(&pitch);
            stream->Write(&roll);

            WriteLinks(stream);
        }

    }

}