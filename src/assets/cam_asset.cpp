#include "hiphop/assets/cam_asset.h"

namespace HipHop {

    void CamAsset::Read(Stream* stream)
    {
        BaseAsset::Read(stream);

        pos.Read(stream);
        at.Read(stream);
        up.Read(stream);
        right.Read(stream);
        view_offset.Read(stream);
        stream->Read(&offset_start_frames);
        stream->Read(&offset_end_frames);
        stream->Read(&fov);
        stream->Read(&trans_time);

        int32_t transtype = (int32_t)trans_type;

        stream->Read(&transtype);
        stream->Read(&flags);
        stream->Read(&fade_up);
        stream->Read(&fade_down);
        stream->Read(&cam_follow.rotation);
        stream->Read(&cam_follow.distance);
        stream->Read(&cam_follow.height);
        stream->Read(&cam_follow.rubber_band);
        stream->Read(&cam_follow.start_speed);
        stream->Read(&cam_follow.end_speed);
        stream->Read(&valid_flags);
        stream->Read(markerid, sizeof(markerid));
        stream->Read(&cam_type);
        stream->Align(4);

        ReadLinks(stream);
    }

    void CamAsset::Write(Stream* stream)
    {
        BaseAsset::Write(stream);

        pos.Write(stream);
        at.Write(stream);
        up.Write(stream);
        right.Write(stream);
        view_offset.Write(stream);
        stream->Write(&offset_start_frames);
        stream->Write(&offset_end_frames);
        stream->Write(&fov);
        stream->Write(&trans_time);

        int32_t transtype = (int32_t)trans_type;

        stream->Write(&transtype);
        stream->Write(&flags);
        stream->Write(&fade_up);
        stream->Write(&fade_down);
        stream->Write(&cam_follow.rotation);
        stream->Write(&cam_follow.distance);
        stream->Write(&cam_follow.height);
        stream->Write(&cam_follow.rubber_band);
        stream->Write(&cam_follow.start_speed);
        stream->Write(&cam_follow.end_speed);
        stream->Write(&valid_flags);
        stream->Write(markerid, sizeof(markerid));
        stream->Write(&cam_type);
        stream->Align(4);

        WriteLinks(stream);
    }

}