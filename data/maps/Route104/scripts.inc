Route104_MapScripts:: @ 814EE8C
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route104_MapScript2_14EE97
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MapScript1_14EEA8
	.byte 0

Route104_MapScript2_14EE97:: @ 814EE97
	map_script_2 VAR_BOARD_BRINEY_BOAT_ROUTE104_STATE, 1, Route104_EventScript_14EEA1
	.2byte 0

Route104_EventScript_14EEA1:: @ 814EEA1
	lockall
	goto Route104_EventScript_14EFD5
	end

Route104_MapScript1_14EEA8:: @ 814EEA8
	call Route104_EventScript_14EEAE
	end

Route104_EventScript_14EEAE:: @ 814EEAE
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_EventScript_14EEC4
	goto_if_unset FLAG_BADGE03_GET, Route104_EventScript_14EEC4
	clearflag FLAG_HIDE_FLOWER_SHOP_WORKER_OUTSIDE
	return

Route104_EventScript_14EEC4:: @ 814EEC4
	setflag FLAG_HIDE_FLOWER_SHOP_WORKER_OUTSIDE
	return

Route104_EventScript_14EEC8:: @ 814EEC8
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHESTO_BERRY_ROUTE104, Route104_EventScript_14EEFF
	msgbox Route104_Text_1C55B9, MSGBOX_DEFAULT
	giveitem ITEM_CHESTO_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHESTO_BERRY_ROUTE104
	msgbox Route104_Text_1C5665, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_14EEFF:: @ 814EEFF
	msgbox Route104_Text_1C5665, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_14EF09:: @ 814EF09
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WHITE_HERB, Route104_EventScript_14EF38
	msgbox Route104_Text_16DD91, MSGBOX_DEFAULT
	giveitem ITEM_WHITE_HERB
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_WHITE_HERB
	release
	end

Route104_EventScript_14EF38:: @ 814EF38
	msgbox Route104_Text_16DE36, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_14EF42:: @ 814EF42
	msgbox Route104_Text_16DA13, MSGBOX_NPC
	end

Route104_EventScript_14EF4B:: @ 814EF4B
	msgbox Route104_Text_16DA89, MSGBOX_SIGN
	end

Route104_EventScript_14EF54:: @ 814EF54
	msgbox Route104_Text_16DEB3, MSGBOX_SIGN
	end

Route104_EventScript_14EF5D:: @ 814EF5D
	msgbox Route104_Text_16DEC8, MSGBOX_SIGN
	end

Route104_EventScript_14EF66:: @ 814EF66
	msgbox Route104_Text_16DEE3, MSGBOX_SIGN
	end

Route104_EventScript_14EF6F:: @ 814EF6F
	msgbox Route104_Text_16DEFD, MSGBOX_SIGN
	end

Route104_EventScript_14EF78:: @ 814EF78
	msgbox Route104_Text_16DF16, MSGBOX_SIGN
	end

Route104_EventScript_14EF81:: @ 814EF81
	msgbox Route104_Text_16DAC9, MSGBOX_NPC
	end

Route104_EventScript_14EF8A:: @ 814EF8A
	msgbox Route104_Text_16DB5C, MSGBOX_NPC
	end

Route104_EventScript_14EF93:: @ 814EF93
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM09, Route104_EventScript_14EFC2
	msgbox Route104_Text_16DC5F, MSGBOX_DEFAULT
	giveitem ITEM_TM09_BULLET_SEED
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM09
	release
	end

Route104_EventScript_14EFC2:: @ 814EFC2
	msgbox Route104_Text_16DD0E, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_14EFCC:: @ 814EFCC
	msgbox Route104_Text_16DBC9, MSGBOX_NPC
	end

Route104_EventScript_14EFD5:: @ 814EFD5
	setobjectpriority 8, MAP_ROUTE104, 0
	setobjectpriority 255, MAP_ROUTE104, 0
	applymovement 8, Route104_Movement_14F16C
	waitmovement 0
	removeobject 8
	applymovement LOCALID_PLAYER, Route104_Movement_14F162
	waitmovement 0
	hideobjectat LOCALID_PLAYER, MAP_ROUTE104
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement 7, Route104_Movement_14F09F
	applymovement LOCALID_PLAYER, Route104_Movement_14F09F
	waitmovement 0
	applymovement LOCALID_PLAYER, Route104_Movement_14F166
	waitmovement 0
	call Common_EventScript_StopBrineysBoatMusic
	showobjectat LOCALID_PLAYER, MAP_DEWFORD_TOWN
	applymovement LOCALID_PLAYER, Route104_Movement_14F168
	waitmovement 0
	setobjectxyperm 2, 12, 8
	addobject 2
	setobjectpriority 2, MAP_DEWFORD_TOWN, 0
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	applymovement 2, Route104_Movement_14F16F
	waitmovement 0
	addobject 4
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD
	call Common_EventScript_StopBrineysBoatMusic
	setflag FLAG_HIDE_MR_BRINEY_BOAT_ROUTE104
	hideobjectat 7, MAP_ROUTE104
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	resetobjectpriority LOCALID_PLAYER, MAP_ROUTE104
	resetobjectpriority 2, MAP_DEWFORD_TOWN
	moveobjectoffscreen 2
	setvar VAR_BOARD_BRINEY_BOAT_ROUTE104_STATE, 0
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_14F08B
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_14F095
	end

Route104_EventScript_14F08B:: @ 814F08B
	msgbox Route104_Text_LandedInDewfordDeliverLetter, MSGBOX_DEFAULT
	releaseall
	end

Route104_EventScript_14F095:: @ 814F095
	msgbox Route104_Text_BrineyLandedInDewford, MSGBOX_DEFAULT
	releaseall
	end

Route104_Movement_14F09F:: @ 814F09F
	walk_down
	walk_down
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_down
	walk_down
	step_end

Route104_Movement_14F162:: @ 814F162
	walk_left
	walk_down
	walk_down
	step_end

Route104_Movement_14F166:: @ 814F166
	walk_down
	step_end

Route104_Movement_14F168:: @ 814F168
	walk_down
	walk_left
	walk_in_place_fastest_right
	step_end

Route104_Movement_14F16C:: @ 814F16C
	walk_down
	walk_down
	step_end

Route104_Movement_14F16F:: @ 814F16F
	walk_down
	walk_in_place_fastest_left
	step_end

Route104_EventScript_14F172:: @ 814F172
	trainerbattle_single TRAINER_IVAN, Route104_Text_1B85EB, Route104_Text_1B8637
	msgbox Route104_Text_1B8680, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_14F189:: @ 814F189
	trainerbattle_single TRAINER_BILLY, Route104_Text_1B86BE, Route104_Text_1B86E8
	msgbox Route104_Text_1B871C, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_14F1A0:: @ 814F1A0
	trainerbattle_single TRAINER_HALEY_1, Route104_Text_1B8770, Route104_Text_1B87A7
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route104_EventScript_14F1C7
	msgbox Route104_Text_1B87C3, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_14F1C7:: @ 814F1C7
	trainerbattle_rematch TRAINER_HALEY_1, Route104_Text_1B8839, Route104_Text_1B8852
	msgbox Route104_Text_1B8872, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_14F1DE:: @ 814F1DE
	trainerbattle_single TRAINER_WINSTON_1, Route104_Text_1B88D4, Route104_Text_1B8911
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route104_EventScript_14F205
	msgbox Route104_Text_1B8925, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_14F205:: @ 814F205
	trainerbattle_rematch TRAINER_WINSTON_1, Route104_Text_1B895E, Route104_Text_1B899E
	msgbox Route104_Text_1B89C0, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_14F21C:: @ 814F21C
	trainerbattle_single TRAINER_CINDY_1, Route104_Text_1B8A24, Route104_Text_1B8A61
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route104_EventScript_14F243
	msgbox Route104_Text_1B8A69, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_14F243:: @ 814F243
	trainerbattle_rematch TRAINER_CINDY_1, Route104_Text_1B8AA7, Route104_Text_1B8AD9
	msgbox Route104_Text_1B8B02, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_14F25A:: @ 814F25A
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_1B83E9, Route104_Text_1B8414, Route104_Text_1B845C
	special GetPlayerBigGuyGirlString
	msgbox Route104_Text_1B842C, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_14F279:: @ 814F279
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_1B84DB, Route104_Text_1B850D, Route104_Text_1B8577
	special GetPlayerBigGuyGirlString
	msgbox Route104_Text_1B853B, MSGBOX_DEFAULT
	release
	end
