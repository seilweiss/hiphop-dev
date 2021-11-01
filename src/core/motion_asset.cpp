#include "hiphop/core/motion_asset.h"

#include "hiphop/core/file.h"

namespace HipHop {

    void MotionAsset::Read(Stream* stream, Asset asset)
    {
        size_t start = stream->Tell();

        stream->Read(&type);
        stream->Read(&use_banking);
        stream->Read(&flags);

        switch (type)
        {
        case ExtendRetract:
        {
            er.ret_pos.Read(stream);
            er.ext_dpos.Read(stream);
            stream->Read(&er.ext_tm);
            stream->Read(&er.ext_wait_tm);
            stream->Read(&er.ret_tm);
            stream->Read(&er.ret_wait_tm);
            break;
        }
        case Orbit:
        {
            orb.center.Read(stream);
            stream->Read(&orb.w);
            stream->Read(&orb.h);
            stream->Read(&orb.period);
            break;
        }
        case Spline:
        {
            if (asset.GetFile()->GetGame() >= Game::SpongeBobMovie)
            {
                stream->Read(&spl.spline_id);
                stream->Read(&spl.speed);
                stream->Read(&spl.lean_modifier);
            }
            else
            {
                stream->Read(&spl.unknown);
            }

            break;
        }
        case MovePoint:
        {
            stream->Read(&mp.flags);
            stream->Read(&mp.mp_id);
            stream->Read(&mp.speed);
            break;
        }
        case Mechanism:
        {
            stream->Read(&mech.type);
            stream->Read(&mech.flags);
            stream->Read(&mech.sld_axis);
            stream->Read(&mech.rot_axis);

            if (asset.GetFile()->GetGame() >= Game::SpongeBobMovie)
            {
                stream->Read(&mech.scale_axis);
                stream->Align(4);
            }

            stream->Read(&mech.sld_dist);
            stream->Read(&mech.sld_tm);
            stream->Read(&mech.sld_acc_tm);
            stream->Read(&mech.sld_dec_tm);
            stream->Read(&mech.rot_dist);
            stream->Read(&mech.rot_tm);
            stream->Read(&mech.rot_acc_tm);
            stream->Read(&mech.rot_dec_tm);
            stream->Read(&mech.ret_delay);
            stream->Read(&mech.post_ret_delay);

            if (asset.GetFile()->GetGame() >= Game::SpongeBobMovie)
            {
                stream->Read(&mech.scale_amount);
                stream->Read(&mech.scale_duration);
            }

            break;
        }
        case Pendulum:
        {
            stream->Read(&pen.flags);
            stream->Read(&pen.plane);
            stream->Align(4);
            stream->Read(&pen.len);
            stream->Read(&pen.range);
            stream->Read(&pen.period);
            stream->Read(&pen.phase);
            break;
        }
        }

        if (asset.GetFile()->GetGame() >= Game::SpongeBobMovie)
        {
            stream->Seek(start + 0x3C);
        }
        else
        {
            stream->Seek(start + 0x30);
        }
    }

    void MotionAsset::Write(Stream* stream, Asset asset)
    {
        size_t start = stream->Tell();

        stream->Write(&type);
        stream->Write(&use_banking);
        stream->Write(&flags);

        switch (type)
        {
        case ExtendRetract:
        {
            er.ret_pos.Write(stream);
            er.ext_dpos.Write(stream);
            stream->Write(&er.ext_tm);
            stream->Write(&er.ext_wait_tm);
            stream->Write(&er.ret_tm);
            stream->Write(&er.ret_wait_tm);
            break;
        }
        case Orbit:
        {
            orb.center.Write(stream);
            stream->Write(&orb.w);
            stream->Write(&orb.h);
            stream->Write(&orb.period);
            break;
        }
        case Spline:
        {
            if (asset.GetFile()->GetGame() >= Game::SpongeBobMovie)
            {
                stream->Write(&spl.spline_id);
                stream->Write(&spl.speed);
                stream->Write(&spl.lean_modifier);
            }
            else
            {
                stream->Write(&spl.unknown);
            }

            break;
        }
        case MovePoint:
        {
            stream->Write(&mp.flags);
            stream->Write(&mp.mp_id);
            stream->Write(&mp.speed);
            break;
        }
        case Mechanism:
        {
            stream->Write(&mech.type);
            stream->Write(&mech.flags);
            stream->Write(&mech.sld_axis);
            stream->Write(&mech.rot_axis);

            if (asset.GetFile()->GetGame() >= Game::SpongeBobMovie)
            {
                stream->Write(&mech.scale_axis);
                stream->Align(4);
            }

            stream->Write(&mech.sld_dist);
            stream->Write(&mech.sld_tm);
            stream->Write(&mech.sld_acc_tm);
            stream->Write(&mech.sld_dec_tm);
            stream->Write(&mech.rot_dist);
            stream->Write(&mech.rot_tm);
            stream->Write(&mech.rot_acc_tm);
            stream->Write(&mech.rot_dec_tm);
            stream->Write(&mech.ret_delay);
            stream->Write(&mech.post_ret_delay);

            if (asset.GetFile()->GetGame() >= Game::SpongeBobMovie)
            {
                stream->Write(&mech.scale_amount);
                stream->Write(&mech.scale_duration);
            }

            break;
        }
        case Pendulum:
        {
            stream->Write(&pen.flags);
            stream->Write(&pen.plane);
            stream->Align(4);
            stream->Write(&pen.len);
            stream->Write(&pen.range);
            stream->Write(&pen.period);
            stream->Write(&pen.phase);
            break;
        }
        }

        if (asset.GetFile()->GetGame() >= Game::SpongeBobMovie)
        {
            stream->Seek(start + 0x3C);
        }
        else
        {
            stream->Seek(start + 0x30);
        }
    }

}