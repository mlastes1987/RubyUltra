PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles:: @ 81A0693
	applymovement LOCALID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoor_Frame, 0
	setmetatile 6, 2, METATILE_EliteFour_OpenDoor_Opening, 0
	setmetatile 0, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 1, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 2, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 3, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 4, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 8, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 9, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 10, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 11, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 12, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	special DrawWholeMapView
	return

PokemonLeague_EliteFour_EventScript_WalkInCloseDoor:: @ 81A0710
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp6
	waitmovement 0
	playse SE_TRUCK_DOOR
	setmetatile 5, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 6, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 7, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 5, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 6, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 7, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	special DrawWholeMapView
	return

@ Essentially unused, only necessary when re-entering an Elite Four room after defeating the member, which isnt normally possible
PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom:: @ 81A0757
	setmetatile 6, 1, METATILE_EliteFour_OpenDoor_Frame, 0
	setmetatile 6, 2, METATILE_EliteFour_OpenDoor_Opening, 0
	setmetatile 5, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 6, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 7, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 5, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 6, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 7, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 0, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 1, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 2, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 3, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 4, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 8, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 9, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 10, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 11, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 12, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	return

PokemonLeague_EliteFour_EventScript_CloseDoor:: @ 81A07FA
	setmetatile 5, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 6, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 7, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 5, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 6, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 7, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	return
