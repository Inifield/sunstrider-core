
#ifndef OUTDOOR_PVP_ZM_
#define OUTDOOR_PVP_ZM_

#include "OutdoorPvP.h"
#include "Language.h"

const uint32 OutdoorPvPZMBuffZonesNum = 5;
// the buff is cast in these zones
const uint32 OutdoorPvPZMBuffZones[OutdoorPvPZMBuffZonesNum] = {3521,3607,3717,3715,3716};
// cast on the players of the controlling faction
const uint32 ZM_CAPTURE_BUFF = 33779;  // twin spire blessing
// spell that the field scout casts on the player to carry the flag
const uint32 ZM_BATTLE_STANDARD_A = 32430;
// spell that the field scout casts on the player to carry the flag
const uint32 ZM_BATTLE_STANDARD_H = 32431;
// linked when the central tower is controlled
const uint32 ZM_GRAVEYARD_ZONE = 3521;
// linked when the central tower is controlled
const uint32 ZM_GRAVEYARD_ID = 969;
// token create spell
const uint32 ZM_AlliancePlayerKillReward = 32155;
// token create spell
const uint32 ZM_HordePlayerKillReward = 32158;

// banners 182527, 182528, 182529, gotta check them ingame
const go_type ZM_Banner_A = { 182527,530,253.54f,7083.81f,36.7728f,-0.017453f,0.0f,0.0f,0.008727f,-0.999962f };
const go_type ZM_Banner_H = { 182528,530,253.54f,7083.81f,36.7728f,-0.017453f,0.0f,0.0f,0.008727f,-0.999962f };
const go_type ZM_Banner_N = { 182529,530,253.54f,7083.81f,36.7728f,-0.017453f,0.0f,0.0f,0.008727f,-0.999962f };

// horde field scout spawn data
const creature_type ZM_HordeFieldScout = {18564,67,530,296.625f,7818.4f,42.6294f,5.18363f};
// alliance field scout spawn data
const creature_type ZM_AllianceFieldScout = {18581,469,530,374.395f,6230.08f,22.8351f,0.593412f};

enum ZMCreatureTypes{
    ZM_ALLIANCE_FIELD_SCOUT = 0,
    ZM_HORDE_FIELD_SCOUT,
    ZM_CREATURE_NUM
};

struct zm_beacon {
    uint32 slider_disp;
    uint32 slider_n;
    uint32 slider_pos;
    uint32 ui_tower_n;
    uint32 ui_tower_h;
    uint32 ui_tower_a;
    uint32 map_tower_n;
    uint32 map_tower_h;
    uint32 map_tower_a;
    uint32 event_enter;
    uint32 event_leave;
};

enum ZM_BeaconType{
    ZM_BEACON_EAST = 0,
    ZM_BEACON_WEST,
    ZM_NUM_BEACONS
};

const zm_beacon ZMBeaconInfo[ZM_NUM_BEACONS] = {
    {2533,2535,2534,2560,2559,2558,2652,2651,2650,11807,11806},
    {2527,2529,2528,2557,2556,2555,2646,2645,2644,11805,11804}
};

const uint32 ZMBeaconCaptureA[ZM_NUM_BEACONS] = {
    LANG_OPVP_ZM_CAPTURE_EAST_A,
    LANG_OPVP_ZM_CAPTURE_WEST_A
};

const uint32 ZMBeaconCaptureH[ZM_NUM_BEACONS] = {
    LANG_OPVP_ZM_CAPTURE_EAST_H,
    LANG_OPVP_ZM_CAPTURE_WEST_H
};

const uint32 ZMBeaconLooseA[ZM_NUM_BEACONS] = {
    LANG_OPVP_ZM_LOOSE_EAST_A,
    LANG_OPVP_ZM_LOOSE_WEST_A
};

const uint32 ZMBeaconLooseH[ZM_NUM_BEACONS] = {
    LANG_OPVP_ZM_LOOSE_EAST_H,
    LANG_OPVP_ZM_LOOSE_WEST_H
};

const go_type ZMCapturePoints[ZM_NUM_BEACONS] = {
    {182523,530,303.243f,6841.36f,40.1245f,-1.58825f,0.0f,0.0f,0.71325f,-0.700909f},
    {182522,530,336.466f,7340.26f,41.4984f,-1.58825f,0.0f,0.0f,0.71325f,-0.700909f}
};

enum OutdoorPvPZMWorldStates
{
    ZM_UI_TOWER_SLIDER_N_W = 2529,
    ZM_UI_TOWER_SLIDER_POS_W = 2528,
    ZM_UI_TOWER_SLIDER_DISPLAY_W = 2527,

    ZM_UI_TOWER_SLIDER_N_E = 2535,
    ZM_UI_TOWER_SLIDER_POS_E = 2534,
    ZM_UI_TOWER_SLIDER_DISPLAY_E = 2533,

    ZM_WORLDSTATE_UNK_1 = 2653,

    ZM_UI_TOWER_EAST_N = 2560,
    ZM_UI_TOWER_EAST_H = 2559,
    ZM_UI_TOWER_EAST_A = 2558,
    ZM_UI_TOWER_WEST_N = 2557,
    ZM_UI_TOWER_WEST_H = 2556,
    ZM_UI_TOWER_WEST_A = 2555,

    ZM_MAP_TOWER_EAST_N = 2652,
    ZM_MAP_TOWER_EAST_H = 2651,
    ZM_MAP_TOWER_EAST_A = 2650,
    ZM_MAP_GRAVEYARD_H = 2649,
    ZM_MAP_GRAVEYARD_A = 2648,
    ZM_MAP_GRAVEYARD_N = 2647,
    ZM_MAP_TOWER_WEST_N = 2646,
    ZM_MAP_TOWER_WEST_H = 2645,
    ZM_MAP_TOWER_WEST_A = 2644,

    ZM_MAP_HORDE_FLAG_READY = 2658,
    ZM_MAP_HORDE_FLAG_NOT_READY = 2657,
    ZM_MAP_ALLIANCE_FLAG_NOT_READY = 2656,
    ZM_MAP_ALLIANCE_FLAG_READY = 2655
};

enum ZM_TowerStateMask{
    ZM_TOWERSTATE_N = 1,
    ZM_TOWERSTATE_A = 2,
    ZM_TOWERSTATE_H = 4
};

class OutdoorPvPZM;
class OPvPCapturePointZM_Beacon : public OPvPCapturePoint
{
friend class OutdoorPvPZM;
public:
    OPvPCapturePointZM_Beacon(OutdoorPvP * pvp, ZM_BeaconType type);
	void ChangeState() override;
    void FillInitialWorldStates(WorldPacket & data) override;
    void UpdateTowerState();
protected:
    ZM_BeaconType m_TowerType;
    uint32 m_TowerState;
};

enum ZM_GraveYardState{
    ZM_GRAVEYARD_N = 1,
    ZM_GRAVEYARD_A = 2,
    ZM_GRAVEYARD_H = 4
};

class OPvPCapturePointZM_GraveYard : public OPvPCapturePoint
{
friend class OutdoorPvPZM;
public:
    OPvPCapturePointZM_GraveYard(OutdoorPvP * pvp);
    bool Update(uint32 diff) override;
	void ChangeState() override { }
    void FillInitialWorldStates(WorldPacket & data) override;
    void UpdateTowerState();
    int32 HandleOpenGo(Player *plr, ObjectGuid guid) override;
    void SetBeaconState(uint32 controlling_team); // not good atm
    bool HandleGossipOption(Player * plr, ObjectGuid guid, uint32 gossipid) override;
    bool HandleDropFlag(Player * plr, uint32 spellId) override;
    bool CanTalkTo(Player * plr, Creature * c, GossipMenuItems const& gso) override;
private:
    uint32 m_GraveYardState;
protected:
    uint32 m_BothControllingFaction;
    ObjectGuid m_FlagCarrierGUID;
};

class OutdoorPvPZM : public OutdoorPvP
{
friend class OPvPCapturePointZM_Beacon;
public:
    OutdoorPvPZM();
    bool SetupOutdoorPvP() override;
    void HandlePlayerEnterZone(Player *plr, uint32 zone) override;
    void HandlePlayerLeaveZone(Player *plr, uint32 zone) override;
    bool Update(uint32 diff) override;
    void FillInitialWorldStates(WorldPacket &data) override;
    void SendRemoveWorldStates(Player * plr) override;
    void HandleKillImpl(Player * plr, Unit * killed) override;
    void BuffTeam(uint32 team);
private:
    OPvPCapturePointZM_GraveYard * m_GraveYard;
    uint32 m_AllianceTowersControlled;
    uint32 m_HordeTowersControlled;
};

// todo: flag carrier death/leave/mount/activitychange should give back the gossip options
#endif