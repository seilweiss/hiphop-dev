#include "hiphop.h"

#include "hiphop_bfbb.h"

using namespace HipHop;

int main(int argc, char** argv)
{
#if 0
    File hip("bb01.HIP");

    hip.Create(Game::BattleForBikiniBottom, Platform::GameCube);

    auto counter = hip.CreateAsset<CounterAsset>("COUNTER_01");
    counter.count = 5;
    counter.links.push_back({ Event::Expired, Event::GiveShinyObjects, Asset("SPONGEBOB"), 100.0f });
    counter.Save();

    auto timer = hip.CreateAsset<TimerAsset>("TIMER_01");
    timer.seconds = 1.0f;
    timer.links.push_back({ Event::SceneBegin, Event::Run, timer });
    timer.links.push_back({ Event::Expired, Event::Decrement, counter });
    timer.links.push_back({ Event::Expired, Event::Reset, timer });
    timer.links.push_back({ Event::Expired, Event::Run, timer });
    timer.Save();

    auto tbox = hip.CreateAsset<Dyna::TeleportAsset>("TBOX_01");
    tbox.links.push_back({ Event::SceneBegin, Event::OpenTBox, tbox });
    tbox.Save();

    auto pointer = hip.CreateAsset<Dyna::PointerAsset>("POINTER_01");
    pointer.loc = { 5.0f, 3.0f, 7.0f };
    pointer.yaw = Math::Deg2Rad(90.0f);
    pointer.pitch = Math::Deg2Rad(90.0f);
    pointer.roll = Math::Deg2Rad(90.0f);
    pointer.Save();

    auto busStop = hip.CreateAsset<Dyna::BusStopAsset>("BUS_STOP_01");
    busStop.character = 1;
    busStop.delay = 5.0f;
    busStop.links.push_back({ Event::SceneBegin, Event::BusStopSwitchChr, busStop });
    busStop.Save();

    auto textAsset = hip.CreateAsset<TextAsset>("text_01");
    textAsset.text = "Hello World!";
    textAsset.Save();

    auto taxi = hip.CreateAsset<Dyna::TaxiAsset>("TAXI_01");
    taxi.textID = textAsset;
    taxi.links.push_back({ Event::SceneBegin, Event::Run, timer });
    taxi.Save();

    auto dpat = hip.CreateAsset<DispatcherAsset>("DPAT_01");
    dpat.links.push_back({ Event::SceneBegin, Event::Disable, taxi });
    dpat.Save();

    auto player = hip.CreateAsset<PlayerAsset>("SPONGEBOB");
    player.pos = { 30.0f, 50.0f, 90.0f };
    player.ang = Math::Deg2Rad({ 90.0f, 0.0f, 0.0f });
    player.Save();

    auto portal = hip.CreateAsset<PortalAsset>("PORTAL_01");
    portal.ang = 5.0f;
    portal.sceneID = 'HB01';
    portal.Save();

    auto animlist = hip.CreateAsset<AnimListAsset>("ANIMLIST_01");
    animlist.ids[0] = Util::Hash("SPONGEBOB");
    animlist.Save();

    auto boulder = hip.CreateAsset<BoulderAsset>("BOULDER_01");
    boulder.Save();

    auto button = hip.CreateAsset<ButtonAsset>("BUTTON_01");
    button.Init(ButtonAsset::PressurePlate);
    button.Save();

    auto cam = hip.CreateAsset<CamAsset>("CAM_01");
    cam.Save();

    auto collTable = hip.CreateAsset<CollTableAsset>("coll table");
    collTable.Save();

    auto cond = hip.CreateAsset<CondAsset>("COND_01");
    cond.constNum = 5;
    cond.expr1 = Util::Hash("Counter Value");
    cond.op = CondAsset::GreaterThan;
    cond.value_asset = counter;
    cond.Save();

    hip.Write();

#elif 0
    File hip("bb01.HIP");

    if (!hip.Read())
    {
        return 1;
    }

    hip.Write();

#elif 1
    File hip("C:\\heavyiron\\tssm\\gc\\backup\\files\\DE\\de01.HIP");

    if (!hip.Read())
    {
        return 1;
    }
#endif

    return 0;
}