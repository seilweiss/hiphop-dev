#include "hiphop/assets/button_asset.h"

namespace HipHop {

    void ButtonAsset::Init(ActMethod actMethod)
    {
        this->actMethod = actMethod;

        switch (actMethod)
        {
        case Button:
        {
            modelInfoID = Util::Hash("button");
            modelPressedInfoID = Util::Hash("button_grn");
            motion.type = MotionAsset::Mechanism;
            motion.flags = MotionAsset::Stopped;
            motion.mech.type = MotionMechData::SlideAndRotate;
            motion.mech.flags = MotionMechData::ReturnToStart;
            motion.mech.sld_axis = MotionMechData::Y;
            motion.mech.sld_dist = -0.25f;
            motion.mech.sld_tm = 0.15f;
            motion.mech.sld_acc_tm = 0.0f;
            motion.mech.sld_dec_tm = 0.0f;
            break;
        }
        case PressurePlate:
        {
            modelInfoID = Util::Hash("plate_pressure");
            modelPressedInfoID = 0xCE7F8131;
            motion.type = MotionAsset::Mechanism;
            motion.flags = MotionAsset::Stopped;
            motion.mech.type = MotionMechData::SlideAndRotate;
            motion.mech.flags = MotionMechData::ReturnToStart;
            motion.mech.sld_axis = MotionMechData::Y;
            motion.mech.sld_dist = -0.15f;
            motion.mech.sld_tm = 0.15f;
            motion.mech.sld_acc_tm = 0.0f;
            motion.mech.sld_dec_tm = 0.0f;
            break;
        }
        }
    }

    void ButtonAsset::Read(Stream* stream)
    {
        EntAsset::Read(stream);

        stream->Read(&modelPressedInfoID);
        stream->Read(&actMethod);
        stream->Read(&initButtonState);
        stream->Read(&isReset);
        stream->Read(&resetDelay);
        stream->Read(&buttonActFlags);

        motion.Read(stream, GetAsset());

        ReadLinks(stream);
    }

    void ButtonAsset::Write(Stream* stream)
    {
        EntAsset::Write(stream);

        stream->Write(&modelPressedInfoID);
        stream->Write(&actMethod);
        stream->Write(&initButtonState);
        stream->Write(&isReset);
        stream->Write(&resetDelay);
        stream->Write(&buttonActFlags);

        motion.Write(stream, GetAsset());

        WriteLinks(stream);
    }

}