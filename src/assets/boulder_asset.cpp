#include "hiphop/assets/boulder_asset.h"

#include "hiphop/core/file.h"

namespace HipHop {

    void BoulderAsset::Read(Stream* stream)
    {
        EntAsset::Read(stream);

        stream->Read(&gravity);
        stream->Read(&mass);
        stream->Read(&bounce);
        stream->Read(&friction);

        if (GetFile()->GetGame() < Game::SpongeBobMovie)
        {
            stream->Read(&statFric);
        }

        stream->Read(&maxVel);
        stream->Read(&maxAngVel);
        stream->Read(&stickiness);
        stream->Read(&bounceDamp);
        stream->Read(&flags);
        stream->Read(&killtimer);
        stream->Read(&hitpoints);
        stream->Read(&soundID);

        if (GetFile()->GetGame() < Game::SpongeBobMovie)
        {
            stream->Read(&volume);
        }

        stream->Read(&minSoundVel);
        stream->Read(&maxSoundVel);

        if (GetFile()->GetGame() < Game::SpongeBobMovie)
        {
            stream->Read(&innerRadius);
            stream->Read(&outerRadius);
        }
        else
        {
            stream->Read(&fSphereRadius);

            uint8_t pad;

            stream->Read(&pad);
            stream->Read(&pad);
            stream->Read(&pad);
            stream->Read(&uBoneIndex);
        }

        ReadLinks(stream);
    }

    void BoulderAsset::Write(Stream* stream)
    {
        EntAsset::Write(stream);

        stream->Write(&gravity);
        stream->Write(&mass);
        stream->Write(&bounce);
        stream->Write(&friction);

        if (GetFile()->GetGame() < Game::SpongeBobMovie)
        {
            stream->Write(&statFric);
        }

        stream->Write(&maxVel);
        stream->Write(&maxAngVel);
        stream->Write(&stickiness);
        stream->Write(&bounceDamp);
        stream->Write(&flags);
        stream->Write(&killtimer);
        stream->Write(&hitpoints);
        stream->Write(&soundID);

        if (GetFile()->GetGame() < Game::SpongeBobMovie)
        {
            stream->Write(&volume);
        }

        stream->Write(&minSoundVel);
        stream->Write(&maxSoundVel);

        if (GetFile()->GetGame() < Game::SpongeBobMovie)
        {
            stream->Write(&innerRadius);
            stream->Write(&outerRadius);
        }
        else
        {
            stream->Write(&fSphereRadius);

            uint8_t pad = 0;

            stream->Write(&pad);
            stream->Write(&pad);
            stream->Write(&pad);
            stream->Write(&uBoneIndex);
        }

        WriteLinks(stream);
    }

}