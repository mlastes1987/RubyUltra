RusturfTunnel_MapScripts:: @ 815C745
	map_script MAP_SCRIPT_ON_TRANSITION, RusturfTunnel_MapScript1_15C762
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RusturfTunnel_MapScript2_15C750
	.byte 0

RusturfTunnel_MapScript2_15C750:: @ 815C750
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 4, RusturfTunnel_EventScript_15C7D1
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 5, RusturfTunnel_EventScript_15C7D1
	.2byte 0

RusturfTunnel_MapScript1_15C762:: @ 815C762
	call Common_EventScript_SetupEvilTeamGfxIds
	compare VAR_RUSTURF_TUNNEL_STATE, 2
	call_if_eq RusturfTunnel_EventScript_15C773
	end

RusturfTunnel_EventScript_15C773:: @ 815C773
	setobjectxyperm 7, 13, 4
	setobjectxyperm 6, 13, 5
	return

RusturfTunnel_EventScript_15C782:: @ 815C782
	lock
	faceplayer
	msgbox RusturfTunnel_Text_194766, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_15C799:: @ 815C799
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, RusturfTunnel_EventScript_15C7BC
	setflag FLAG_TEMP_1
	msgbox RusturfTunnel_Text_1944C5, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_15C7BC:: @ 815C7BC
	msgbox RusturfTunnel_Text_1945B2, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_15C7D1:: @ 815C7D1
	lockall
	compare VAR_TEMP_1, 1
	call_if_eq RusturfTunnel_EventScript_15C8CA
	compare VAR_TEMP_1, 2
	call_if_eq RusturfTunnel_EventScript_15C8DF
	compare VAR_TEMP_1, 3
	call_if_eq RusturfTunnel_EventScript_15C8EA
	call RusturfTunnel_EventScript_15C92D
	msgbox RusturfTunnel_Text_19461D, MSGBOX_DEFAULT
	compare VAR_TEMP_1, 2
	call_if_eq RusturfTunnel_EventScript_15C8EB
	compare VAR_TEMP_1, 3
	call_if_eq RusturfTunnel_EventScript_15C8EB
	giveitem ITEM_HM04_STRENGTH
	setflag FLAG_RECEIVED_HM04
	msgbox RusturfTunnel_Text_194693, MSGBOX_DEFAULT
	closemessage
	compare VAR_TEMP_1, 1
	call_if_eq RusturfTunnel_EventScript_15C880
	compare VAR_TEMP_1, 2
	call_if_eq RusturfTunnel_EventScript_15C892
	compare VAR_TEMP_1, 3
	call_if_eq RusturfTunnel_EventScript_15C8AE
	msgbox RusturfTunnel_Text_194706, MSGBOX_DEFAULT
	closemessage
	compare VAR_TEMP_1, 1
	call_if_eq RusturfTunnel_EventScript_15C8F7
	compare VAR_TEMP_1, 2
	call_if_eq RusturfTunnel_EventScript_15C909
	compare VAR_TEMP_1, 3
	call_if_eq RusturfTunnel_EventScript_15C91B
	call RusturfTunnel_EventScript_SetRusturfTunnelOpen
	releaseall
	end

RusturfTunnel_EventScript_15C880:: @ 815C880
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_15C96A
	applymovement 1, RusturfTunnel_Movement_15C98F
	waitmovement 0
	return

RusturfTunnel_EventScript_15C892:: @ 815C892
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_15C96D
	applymovement 1, RusturfTunnel_Movement_15C994
	waitmovement 0
	applymovement 10, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

RusturfTunnel_EventScript_15C8AE:: @ 815C8AE
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_15C96D
	applymovement 1, RusturfTunnel_Movement_15C994
	waitmovement 0
	applymovement 10, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

RusturfTunnel_EventScript_15C8CA:: @ 815C8CA
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

RusturfTunnel_EventScript_15C8DF:: @ 815C8DF
	applymovement 1, RusturfTunnel_Movement_15C970
	waitmovement 0
	return

RusturfTunnel_EventScript_15C8EA:: @ 815C8EA
	return

RusturfTunnel_EventScript_15C8EB:: @ 815C8EB
	closemessage
	applymovement 1, RusturfTunnel_Movement_15C98D
	waitmovement 0
	return

RusturfTunnel_EventScript_15C8F7:: @ 815C8F7
	applymovement 10, RusturfTunnel_Movement_15C945
	applymovement 1, RusturfTunnel_Movement_15C973
	waitmovement 0
	return

RusturfTunnel_EventScript_15C909:: @ 815C909
	applymovement 10, RusturfTunnel_Movement_15C951
	applymovement 1, RusturfTunnel_Movement_15C980
	waitmovement 0
	return

RusturfTunnel_EventScript_15C91B:: @ 815C91B
	applymovement 10, RusturfTunnel_Movement_15C951
	applymovement 1, RusturfTunnel_Movement_15C980
	waitmovement 0
	return

RusturfTunnel_EventScript_15C92D:: @ 815C92D
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RusturfTunnel_Movement_15C945:: @ 815C945
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_15C951:: @ 815C951
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@ 815C95D
	walk_left
	walk_in_place_fastest_right
	step_end

@ 815C960
	walk_down
	walk_in_place_fastest_up
	delay_8
	walk_in_place_fastest_right
	step_end

@ 815C965
	walk_up
	walk_in_place_fastest_down
	delay_8
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_15C96A:: @ 815C96A
	walk_left
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_15C96D:: @ 815C96D
	walk_right
	walk_in_place_fastest_left
	step_end

RusturfTunnel_Movement_15C970:: @ 815C970
	walk_up
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_15C973:: @ 815C973
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_15C980:: @ 815C980
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_15C98D:: @ 815C98D
	walk_right
	step_end

RusturfTunnel_Movement_15C98F:: @ 815C98F
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_fast_up
	walk_fast_right
	step_end

RusturfTunnel_Movement_15C994:: @ 815C994
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_fast_right
	walk_in_place_fastest_up
	step_end

RusturfTunnel_EventScript_15C999:: @ 815C999
	setvar VAR_TEMP_1, 1
	end

RusturfTunnel_EventScript_15C99F:: @ 815C99F
	setvar VAR_TEMP_1, 2
	end

RusturfTunnel_EventScript_15C9A5:: @ 815C9A5
	setvar VAR_TEMP_1, 3
	end

RusturfTunnel_EventScript_15C9AB:: @ 815C9AB
	lockall
	msgbox RusturfTunnel_Text_194159, MSGBOX_DEFAULT
	closemessage
	applymovement 6, RusturfTunnel_Movement_15C9D3
	applymovement 7, RusturfTunnel_Movement_15C9D3
	waitmovement 0
	moveobjectoffscreen 6
	moveobjectoffscreen 7
	setvar VAR_RUSTURF_TUNNEL_STATE, 3
	releaseall
	end

RusturfTunnel_Movement_15C9D3:: @ 815C9D3
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

RusturfTunnel_EventScript_15C9D7:: @ 815C9D7
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, 0
	msgbox RusturfTunnel_Text_194188, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RusturfTunnel_EventScript_15C9EA:: @ 815C9EA
	lock
	faceplayer
	playbgm MUS_EVIL_TEAM, FALSE
	msgbox RusturfTunnel_Text_19419B, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_RUSTURF_TUNNEL_GRUNT, RusturfTunnel_Text_194243
	msgbox RusturfTunnel_Text_194274, MSGBOX_DEFAULT
	giveitem ITEM_DEVON_GOODS
	closemessage
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_15CA99
	applymovement 6, RusturfTunnel_Movement_15CAA2
	waitmovement 0
	removeobject 6
	delay 50
	addobject 5
	applymovement 5, RusturfTunnel_Movement_15CAAC
	waitmovement 0
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_15CA9F
	applymovement 5, RusturfTunnel_Movement_15CAC0
	waitmovement 0
	msgbox RusturfTunnel_Text_19432A, MSGBOX_DEFAULT
	applymovement 5, Common_Movement_FacePlayer
	waitmovement 0
	message RusturfTunnel_Text_19434F
	waitmessage
	waitse
	playmoncry SPECIES_WINGULL, 0
	waitbuttonpress
	waitmoncry
	closemessage
	applymovement 5, RusturfTunnel_Movement_15CAB4
	applymovement 7, RusturfTunnel_Movement_15CAC3
	waitmovement 0
	removeobject 5
	removeobject 7
	clearflag FLAG_DEVON_GOODS_STOLEN
	setflag FLAG_RECOVERED_DEVON_GOODS
	setvar VAR_RUSTBORO_STATE, 4
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setflag FLAG_HIDE_BRINEY_ROUTE116
	release
	end

RusturfTunnel_Movement_15CA99:: @ 815CA99
	face_down
	lock_facing_direction
	walk_up
	unlock_facing_direction
	walk_in_place_fastest_left
	step_end

RusturfTunnel_Movement_15CA9F:: @ 815CA9F
	walk_down
	walk_in_place_fastest_up
	step_end

RusturfTunnel_Movement_15CAA2:: @ 815CAA2
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

RusturfTunnel_Movement_15CAAC:: @ 815CAAC
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RusturfTunnel_Movement_15CAB4:: @ 815CAB4
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RusturfTunnel_Movement_15CAC0:: @ 815CAC0
	delay_16
	walk_right
	step_end

RusturfTunnel_Movement_15CAC3:: @ 815CAC3
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RusturfTunnel_EventScript_15CACD:: @ 815CACD
	trainerbattle_single TRAINER_MIKE_2, RusturfTunnel_Text_194814, RusturfTunnel_Text_1948A2
	msgbox RusturfTunnel_Text_1948C4, MSGBOX_AUTOCLOSE
	end
