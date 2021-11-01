#pragma once

namespace HipHop {

    namespace Event {

        enum
        {
            Unknown = 0, // Unknown
            Enable, // Enable
            Disable, // Disable
            Visible, // Visible
            Invisible, // Invisible
            EnterPlayer, // EnterPlayer
            ExitPlayer, // ExitPlayer
            TouchPlayer, // TouchPlayer
            ControlOff, // ControlOff
            ControlOn, // ControlOn
            Reset, // Reset
            Increment, // Increment
            Decrement, // Decrement
            Open, // Open
            Close, // Close
            Toggle, // Toggle
            TeleportPlayer, // Teleport Player
            OutOfBounds, // OutOfBounds
            Run, // Run
            Stop, // Stop
            Expired, // Expired
            Move, // Move
            Destroy, // Destroy
            Pause, // Pause
            Play, // Play
            PlayOne, // PlayOne
            PlayMaybe, // PlayMaybe
            RoomStart, // RoomStart
            Invalidate, // Invalidate
            Tilt, // Tilt
            Untilt, // Untilt
            Arrive, // Arrive
            Mount, // Mount
            Dismount, // Dismount
            Break, // Break
            Pickup, // Pickup
            Death, // Death
            Kill, // Kill
            On, // On
            Off, // Off
            NPCPatrolOn, // Patrol On
            NPCPatrolOff, // Patrol Off
            NPCWanderOn, // Wander On
            NPCWanderOff, // Wander Off
            NPCDetectOn, // Detect Player On
            NPCDetectOff, // Detect Player Off
            NPCChaseOn, // Chase Player On
            NPCChaseOff, // Chase Player Off
            NPCGoToSleep, // Go To Sleep
            NPCWakeUp, // Wake Up Villain
            NPCRespawn, // Respawn
            PlayerDeath, // PlayerDeath
            GiveChance, // GiveChance
            GiveShinyObjects, // GiveShinyObjects
            GiveHealth, // GiveHealth
            Press, // ButtonPress
            Unpress, // ButtonUnpress
            ArriveHalfway, // ArriveHalfway
            Hit, // Hit
            ButtonPressAction, // ButtonPressAction
            Evaluate, // Evaluate
            True, // True
            False, // False
            PadPressX, // PadPressX
            PadPressSquare, // PadPressSquare
            PadPressO, // PadPressO
            PadPressTriangle, // PadPressTriangle
            PadPressL1, // PadPressL1
            PadPressL2, // PadPressL2
            PadPressR1, // PadPressR1
            PadPressR2, // PadPressR2
            PadPressStart, // PadPressStart
            PadPressSelect, // PadPressSelect
            PadPressUp, // PadPressUp
            PadPressDown, // PadPressDown
            PadPressRight, // PadPressRight
            PadPressLeft, // PadPressLeft
            FontBackdropOn, // FontBackdropOn
            FontBackdropOff, // FontBackdropOff
            UISelect, // UI Select
            UIUnselect, // UI Unselect
            UIFocusOn, // UI Focus On
            UIFocusOff, // UI Focus Off
            CollisionOn, // Collision On
            CollisionOff, // Collision Off
            Collision_Visible_On, // Collision+Visible On
            Collision_Visible_Off, // Collision+Visible Off
            SceneBegin, // Scene Prepare
            SceneEnd, // Scene Finish
            RoomBegin, // Room Prepare
            RoomEnd, // Room Finish
            LobMasterShoot, // LobMaster Shoot
            LobMasterReset, // LobMaster Reset
            FallToDeath, // FallToDeath
            UIFocusOn_Select, // UI Focus On+Select
            UIFocusOff_Unselect, // UI Focus Off+Unselect
            Dispatcher_PadCfg_PresetA, // Set Pad Config to Preset A
            Dispatcher_PadCfg_PresetB, // Set Pad Config to Preset B
            Dispatcher_PadCfg_PresetC, // Set Pad Config to Preset C
            Dispatcher_PadCfg_PresetD, // Set Pad Config to Preset D
            Dispatcher_PadVibrateOn, // Pad Vibrate On
            Dispatcher_PadVibrateOff, // Pad Vibrate Off
            Dispatcher_SoundMono, // Mono Sound
            Dispatcher_SoundStereo, // Stereo Sound
            Dispatcher_SoundMasterIncrease, // Increase Master Volume
            Dispatcher_SoundMasterDecrease, // Decrease Master Volume
            Dispatcher_SoundMusicIncrease, // Increase Music Volume
            Dispatcher_SoundMusicDecrease, // Decrease Music Volume
            Dispatcher_SoundSFXIncrease, // Increase SFX Volume
            Dispatcher_SoundSFXDecrease, // Decrease SFX Volume
            Dispatcher_IntroState_Sony, // IntroState_Sony
            Dispatcher_IntroState_Publisher, // IntroState_Publisher
            Dispatcher_IntroState_Developer, // IntroState_Developer
            Dispatcher_IntroState_License, // IntroState_License
            Dispatcher_IntroState_Count, // IntroState_Count
            Dispatcher_TitleState_Start, // TitleState_Start
            Dispatcher_TitleState_Attract, // TitleState_Attract
            Dispatcher_TitleState_Count, // TitleState_Count
            Dispatcher_LoadState_SelectMemCard, // LoadState_SelectMemCard
            Dispatcher_LoadState_SelectSlot, // LoadState_SelectSlot
            Dispatcher_LoadState_Loading, // LoadState_Loading
            Dispatcher_LoadState_Count, // LoadState_Count
            Dispatcher_OptionsState_Options, // OptionsState_Options
            Dispatcher_OptionsState_Count, // OptionsState_Count
            Dispatcher_SaveState_SelectMemCard, // SaveState_SelectMemCard
            Dispatcher_SaveState_SelectSlot, // SaveState_SelectSlot
            Dispatcher_SaveState_Saving, // SaveState_Saving
            Dispatcher_SaveState_Count, // SaveState_Count
            Dispatcher_PauseState_Pause, // PauseState_Pause
            Dispatcher_PauseState_Options, // PauseState_Options
            Dispatcher_PauseState_Count, // PauseState_Count
            Dispatcher_GameState_FirstTime, // GameState_FirstTime
            Dispatcher_GameState_Play, // GameState_Play
            Dispatcher_GameState_LoseChance, // GameState_LoseChance
            Dispatcher_GameState_GameOver, // GameState_GameOver
            Dispatcher_GameState_SceneSwitch, // GameState_SceneSwitch
            Dispatcher_GameState_Dead, // GameState_Dead
            Dispatcher_SetIntroState_Sony, // SetIntroState_Sony
            Dispatcher_SetIntroState_Publisher, // SetIntroState_Publisher
            Dispatcher_SetIntroState_Developer, // SetIntroState_Developer
            Dispatcher_SetIntroState_License, // SetIntroState_License
            Dispatcher_SetIntroState_Count, // SetIntroState_Count
            Dispatcher_SetTitleState_Start, // SetTitleState_Start
            Dispatcher_SetTitleState_Attract, // SetTitleState_Attract
            Dispatcher_SetTitleState_Count, // SetTitleState_Count
            Dispatcher_SetLoadState_SelectMemCard, // SetLoadState_SelectMemCard
            Dispatcher_SetLoadState_SelectSlot, // SetLoadState_SelectSlot
            Dispatcher_SetLoadState_Loading, // SetLoadState_Loading
            Dispatcher_SetLoadState_Count, // SetLoadState_Count
            Dispatcher_SetOptionsState_Options, // SetOptionsState_Options
            Dispatcher_SetOptionsState_Count, // SetOptionsState_Count
            Dispatcher_SetSaveState_SelectMemCard, // SetSaveState_SelectMemCard
            Dispatcher_SetSaveState_SelectSlot, // SetSaveState_SelectSlot
            Dispatcher_SetSaveState_Saving, // SetSaveState_Saving
            Dispatcher_SetSaveState_Count, // SetSaveState_Count
            Dispatcher_SetPauseState_Pause, // SetPauseState_Pause
            Dispatcher_SetPauseState_Options, // SetPauseState_Options
            Dispatcher_SetPauseState_Count, // SetPauseState_Count
            Dispatcher_SetGameState_FirstTime, // SetGameState_FirstTime
            Dispatcher_SetGameState_Play, // SetGameState_Play
            Dispatcher_SetGameState_LoseChance, // SetGameState_LoseChance
            Dispatcher_SetGameState_GameOver, // SetGameState_GameOver
            Dispatcher_SetGameState_SceneSwitch, // SetGameState_SceneSwitch
            Dispatcher_SetGameState_Dead, // SetGameState_Dead
            Digup, // Digup
            Dispatcher_GameState_Exit, // GameState_Exit
            Dispatcher_SetGameState_Exit, // SetGameState_Exit
            LobMasterShootFromWidget, // LobMaster Shoot From Widget
            Dispatcher_SLBack, // Back
            Dispatcher_SLCancel, // Cancel
            Dispatcher_SLRetry, // Retry
            Dispatcher_SLSelectCard, // Select Card
            Dispatcher_SLSelectSlot, // Select Slot
            Dispatcher_SLOkay, // OK
            VilHurtBoss, // VilHurtBoss
            Attack, // Attack
            AttackOn, // AttackOn
            AttackOff, // AttackOff
            Drop, // Drop pickup
            VilReport_StartingIdle, // VilReport_StartingIdle
            UIAddChar = VilReport_StartingIdle, // UI Add Char
            VilReport_StartingSleep, // VilReport_StartingSleep
            UIDelChar = VilReport_StartingSleep, // UI Del Char
            VilReport_StartingGuard, // VilReport_StartingGuard
            UIStringEmpty = VilReport_StartingGuard, // UI String Empty
            VilReport_StartingPatrol, // VilReport_StartingPatrol
            UIStringFull = VilReport_StartingPatrol, // UI String Full
            VilReport_StartingDazed, // VilReport_StartingDazed
            UISendStringAsCheat = VilReport_StartingDazed, // UI String Send As Cheat
            VilReport_StartingLook, // VilReport_StartingLook
            UISetMaxChars = VilReport_StartingLook, // UI Set Max Chars
            VilReport_StartingListen, // VilReport_StartingListen
            UICheatOK = VilReport_StartingListen, // UI Cheat OK
            VilReport_StartingInvestigate, // VilReport_StartingInvestigate
            UICheatBad = VilReport_StartingInvestigate, // UI Cheat Bad
            VilReport_StartingChase, // VilReport_StartingChase
            VilReport_StartingAttack, // VilReport_StartingAttack
            VilReport_StartingRetreat, // VilReport_StartingRetreat
            Preload, // Preload
            Done, // Done
            Arcto, // Arcto
            DigupReaction, // Digup Reaction
            Dispatcher_StoreCheckPoint, // Set Check Point
            AnimPlay, // AnimPlay
            AnimPlayLoop, // AnimPlayLoop
            AnimStop, // AnimStop
            AnimPause, // AnimPause
            AnimResume, // AnimResume
            AnimTogglePause, // AnimTogglePause
            AnimPlayRandom, // AnimPlayRandom
            AnimPlayMaybe, // AnimPlayMaybe
            SetSpeed, // SetSpeed
            Accelerate, // Accelerate
            MoveToTarget, // MoveToTarget
            SwingerFollow, // SwingerFollow
            ShaggyMount, // ShaggyMount
            Impact = ShaggyMount, // Impact
            ShaggyWitchDrop, // ShaggyWitchDrop
            StartTimer = ShaggyWitchDrop, // StartTimer
            ShaggySwap, // ShaggySwap
            FinishedTimer = ShaggySwap, // FinishedTimer
            ShaggyState, // ShaggyState
            UIReset = ShaggyState, // UI Reset
            ShaggyAction, // ShaggyAction
            SetScaleFactor = ShaggyAction, // SetScaleFactor
            EnterEntity, // EnterEntity
            ExitEntity, // ExitEntity
            EnterEntityFLAG, // ENTER FLAGGED - DO NOT USE
            ExitEntityFLAG, // EXIT FLAGGED - DO NOT USE
            Drivenby, // Drivenby
            FollowTarget, // FollowTarget
            FaceTarget, // FaceTarget
            WatchTarget, // WatchTarget
            ShaggyCollideOnly, // ShaggyCollideOnly
            CarChangeLaneRight = ShaggyCollideOnly, // CarChangeLaneRight
            Shaggy1_ThrowTarget, // Shaggy1_ThrowTarget
            CarChangeLaneLeft = Shaggy1_ThrowTarget, // CarChangeLaneLeft
            Shaggy8_CallEnable, // Shaggy8_CallEnable
            CarStart = Shaggy8_CallEnable, // CarStart
            Shaggy8_CallDisable, // Shaggy8_CallDisable
            CarSetSwerveMode = Shaggy8_CallDisable, // CarSetSwerveMode
            Shaggy8_SetMagnet, // Shaggy8_SetMagnet
            IncreaseSpeed = Shaggy8_SetMagnet, // IncreaseSpeed
            Shaggy8_ClearMagnet, // Shaggy8_ClearMagnet
            DecreaseSpeed = Shaggy8_ClearMagnet, // DecreaseSpeed
            StartMoving, // StartMoving
            StopMoving, // StopMoving
            Swoosh, // Swoosh
            ShaggySetDown, // ShaggySetDown
            TurretDestroyed = ShaggySetDown, // TurretDestroyed
            ShaggyGrabEnable, // ShaggyGrabEnable
            NPCSpeakStop = ShaggyGrabEnable, // NPC Speak Stop
            ShaggyGrabDisable, // ShaggyGrabDisable
            StartRumbleEffect = ShaggyGrabDisable, // StartRumbleEffect
            ShaggyGrabbed, // ShaggyGrabbed
            NavigateTo = ShaggyGrabbed, // Navigate To
            ShaggyThrown, // ShaggyThrown
            NPCSpeakStart = ShaggyThrown, // NPC Speak Start
            VilDoAction, // VilDoAction
            NPCAlert = VilDoAction, // NPC Alert
            GangDoBossAction, // GangDoBossAction
            NPCPatrolDelay = GangDoBossAction, // NPC Patrol Delay
            VilFakeChaseOn, // VilFakeChaseOn
            NPCScrambleActionEnd = VilFakeChaseOn, // NPC Scramble Action End
            VilFakeChaseOff, // VilFakeChaseOff
            BossMMPushButton, // BossMMPushButton
            VilReport_DecayComplete, // VilReport_DecayComplete
            VilGuardWidget, // VilGuardWidget
            TextureAnimateOn, // TextureAnimateOn
            TextureAnimateOff, // TextureAnimateOff
            TextureAnimateToggle, // TextureAnimateToggle
            ColorEffectOn, // ColorEffectOn
            ColorEffectOff, // ColorEffectOff
            ColorEffectToggle, // ColorEffectToggle
            SetTextureAnimGroup, // SetTextureAnimGroup
            SetTextureAnimSpeed, // SetTextureAnimSpeed
            TextureAnimateStep, // TextureAnimateStep
            Emit, // Emit
            Emitted, // Emitted
            TranslucentOn, // TranslucentOn
            TranslucentOff, // TranslucentOff
            TranslucentToggle, // TranslucentToggle
            VilGangTalkOn, // VilGangTalkOn
            ZipLineEnvDamage = VilGangTalkOn, // Zip Line Env Damage
            VilGangTalkOff, // VilGangTalkOff
            GivePowerUp, // Give PowerUp
            UnlockR001, // Unlock R001
            RaceTimerReset = UnlockR001, // RaceTimerReset
            UnlockS001, // Unlock S001
            FireCruiseBubble = UnlockS001, // Fire Cruise Bubble
            UnlockE001, // Unlock E001
            CarSuccessAnimPlay = UnlockE001, // Car Success Anim Play
            UnlockF001, // Unlock F001
            CarFailureAnimPlay = UnlockF001, // Car Failure Anim Play
            DisableGroupContents, // Disable Group Contents
            ShaggyPhysHack, // ShaggyPhysHack
            NPCCharge = ShaggyPhysHack,
            OccludeOn, // OccludeOn
            OccludeOff, // OccludeOff
            WaveSetLinear, // WaveSetLinear - OBSOLETE
            RaceTimerPause = WaveSetLinear, // RaceTimerPause
            WaveSetRipple, // WaveSetRipple - OBSOLETE
            RaceTimerResume = WaveSetRipple, // RaceTimerResume
            SituationLaugh, // SituationLaugh
            RaceTimerSetBestTime = SituationLaugh, // RaceTimerSetBestTime
            SituationBossBattleGreenGhost, // SituationBossBattleGreenGhost
            RaceTimerWarning1 = SituationBossBattleGreenGhost, // RaceTimerWarning1
            SituationBossBattleRedBeard, // SituationBossBattleRedBeard
            RaceTimerWarning2 = SituationBossBattleRedBeard, // RaceTimerWarning2
            SituationBossBattleMasterMind, // SituationBossBattleMasterMind
            RaceTimerWarning3 = SituationBossBattleMasterMind, // RaceTimerWarning3
            SituationBossBattleBlacknight, // SituationBossBattleBlacknight
            RingChallengeStart = SituationBossBattleBlacknight, // RingChallengeStart
            SituationPlayerScare, // SituationPlayerScare
            CarStop = SituationPlayerScare, // Car Stop
            SituationPlayerSafe, // SituationPlayerSafe
            RingChallengeRun = SituationPlayerSafe, // RingChallengeRun
            SituationPlayerDanger, // SituationPlayerDanger
            RingChallengeReset = SituationPlayerDanger, // RingChallengeReset
            SituationPlayerChaseBegin, // SituationPlayerChaseBegin
            RingChallengeSuccess = SituationPlayerChaseBegin, // RingChallengeSuccess
            SituationPlayerChaseEnd, // SituationPlayerChaseEnd
            RingChallengeFailed = SituationPlayerChaseEnd, // RingChallengeFailed
            SituationPlayerSeeShaggy, // SituationPlayerSeeShaggy
            FormationChanged = SituationPlayerSeeShaggy, // Formation Changed
            SituationPlayerSeeFood, // SituationPlayerSeeFood
            ChargeResume = SituationPlayerSeeFood, // Charge Resume
            SituationPlayerSeeToken, // SituationPlayerSeeToken
            ChargePause = SituationPlayerSeeToken, // Charge Pause
            SituationPlayerSeeScoobySnack, // SituationPlayerSeeScoobySnack
            NPCChargeStop = SituationPlayerSeeScoobySnack, // NPC Charge Stop
            SituationPlayerSeePowerup, // SituationPlayerSeePowerup
            NPCChargeCompleted = SituationPlayerSeePowerup, // NPC Charge Completed
            SituationPlayerSeeMonster, // SituationPlayerSeeMonster
            FormationChargeStart = SituationPlayerSeeMonster, // Formation Change Start
            SituationPlayerSuccess, // SituationPlayerSuccess
            SituationPlayerFailure, // SituationPlayerFailure
            Dispatcher_ShowHud, // Show Hud
            Dispatcher_HideHud, // Hide Hud
            Dispatcher_FadeOut,
            SetRain, // SetRain
            SetSnow, // SetSnow
            ShaggyMowerStopMode, // ShaggyMowerStopMode
            ScriptNoop = ShaggyMowerStopMode, // Script No Op
            ScriptReset, // ScriptReset
            WaitForInput, // WaitForInput
            PlayMovie, // Play Movie
            DefeatedMM, // Mastermind is defeated
            CelebrationAnimPlay = DefeatedMM, // CelebrationAnimPlay
            Dispatcher_SetGameState_GameStats, // SetGameState_GameStats
            PlayMusic, // PlayMusic
            MusicNewSong = PlayMusic, // MusicTrack Replace
            Forward, // Forward
            Reverse, // Reverse
            PlayerRumbleTest, // PlayerRumbleTest
            DeprecatedRumbleTest = PlayerRumbleTest, // RumbleTest - OBSOLETE
            PlayerRumbleLight, // PlayerRumbleLight
            DeprecatedRumbleLight = PlayerRumbleLight, // RumbleLight - OBSOLETE
            PlayerRumbleMedium, // PlayerRumbleMedium
            DeprecatedRumbleMedium = PlayerRumbleMedium, // RumbleMedium - OBSOLETE
            PlayerRumbleHeavy, // PlayerRumbleHeavy
            DeprecatedRumbleHeavy = PlayerRumbleHeavy, // RumbleHeavy - OBSOLETE
            DispatcherScreenAdjustON, // Screen Adjustment ON
            DispatcherScreenAdjustOFF, // Screen Adjustment OFF
            SetSkyDome, // Set as Skydome
            ConnectToChild, // Connect_IOwnYou
            DuploWaveBegin, // Duplotron_WaveBegin
            DuploWaveComplete, // Duplotron_WaveComplete
            DuploNPCBorn, // Duplotron_NPCBorn
            DuploNPCKilled, // Duplotron_NPCKilled
            DuploExpiredMaxNPC, // Duplotron_MaxNPCExpired
            DuploPause, // Duplotron_Pause
            DuploResume, // Duplotron_Resume
            SetGoo, // Set as Goo
            NPCScript_ScriptBegin, // NPCScript_ScriptBegin
            NPCScript_ScriptEnd, // NPCScript_ScriptEnd
            NPCScript_ScriptReady, // NPCScript_ScriptReady
            NPCScript_Halt, // NPCScript_Halt
            NPCScript_SetPos, // NPCScript_SetPos
            NPCScript_SetDir, // NPCScript_SetDir
            NPCScript_LookNormal, // NPCScript_LookNormal
            NPCScript_LookAlert, // NPCScript_LookAlert
            NPCScript_FaceWidget, // NPCScript_FaceWidget
            NPCScript_FaceWidgetDone, // NPCScript_FaceWidgetDone
            NPCScript_GotoWidget, // NPCScript_GotoWidget
            NPCScript_GotoWidgetDone, // NPCScript_GotoWidgetDone
            NPCScript_AttackWidget, // NPCScript_AttackWidget
            NPCScript_AttackWidgetDone, // NPCScript_AttackWidgetDone
            NPCScript_FollowWidget, // NPCScript_FollowWidget
            NPCScript_PlayAnim, // NPCScript_PlayAnim
            NPCScript_PlayAnimDone, // NPCScript_PlayAnimDone
            NPCScript_LeadPlayer, // NPCScript_LeadPlayer
            SetText, // Set Text
            StartConversation, // Start Conversation
            EndConversation, // End Conversation
            Switch, // Switch
            AddText, // Add Text
            ClearText, // Clear Text
            OpenTBox, // Open Teleport Box
            CloseTBox, // Close Teleport Box
            TalkBox_OnSignal0, // On Signal 0
            TalkBox_OnSignal1, // On Signal 1
            TalkBox_OnSignal2, // On Signal 2
            TalkBox_OnSignal3, // On Signal 3
            TalkBox_OnSignal4, // On Signal 4
            TalkBox_OnSignal5, // On Signal 5
            TalkBox_OnSignal6, // On Signal 6
            TalkBox_OnSignal7, // On Signal 7
            TalkBox_OnSignal8, // On Signal 8
            TalkBox_OnSignal9, // On Signal 9
            TalkBox_StopWait, // Stop Wait
            TalkBox_OnStart, // On Conversation Start
            TalkBox_OnStop, // On Conversation End
            Hit_Melee, // Hit Melee
            Hit_BubbleBounce, // Hit Bubble Bounce
            Hit_BubbleBash, // Hit Bubble Bash
            Hit_BubbleBowl, // Hit Bubble Bowl
            Hit_PatrickSlam, // Hit Patrick Slam
            Hit_Throw, // Hit By Throwable
            Hit_PaddleLeft, // Paddle Hit Left
            Hit_PaddleRight, // Paddle Hit Right
            TaskBox_Initiate, // Initiate Task
            TaskBox_SetSuccess, // Set Success
            TaskBox_SetFailure, // Set Failure
            TaskBox_OnAccept, // On Accept
            TaskBox_OnDecline, // On Decline
            TaskBox_OnComplete, // On Complete
            GenerateBoulder, // Generate Boulder
            LaunchBoulderAtWidget, // Launch Boulder At Widget
            LaunchBoulderAtPoint, // Launch Boulder At Point
            LaunchBoulderAtPlayer, // Launch Boulder At Player
            DuploSuperDuperDone, // Duplotron_SuperDuperDone
            DuploDuperIsDoner, // Duplotron_DuperIsDoner
            BusStopSwitchChr, // Bus Switch Character
            GroupUpdateTogether, // Group Update Together
            SetUpdateDistance, // Set Update Distance
            TranslLocalX, // Translate, Local X
            TranslLocalY, // Translate, Local Y
            TranslLocalZ, // Translate, Local Z
            TranslWorldX, // Translate, World X
            TranslWorldY, // Translate, World Y
            TranslWorldZ, // Translate, World Z
            RotLocalX, // Rotate, Local X
            RotLocalY, // Rotate, Local Y
            RotLocalZ, // Rotate, Local Z
            RotWorldX, // Rotate, World X
            RotWorldY, // Rotate, World Y
            RotWorldZ, // Rotate, World Z
            TranslLocalXDone, // Translate, Local X Done
            TranslLocalYDone, // Translate, Local Y Done
            TranslLocalZDone, // Translate, Local Z Done
            TranslWorldXDone, // Translate, World X Done
            TranslWorldYDone, // Translate, World Y Done
            TranslWorldZDone, // Translate, World Z Done
            RotLocalXDone, // Rotate, Local X Done
            RotLocalYDone, // Rotate, Local Y Done
            RotLocalZDone, // Rotate, Local Z Done
            RotWorldXDone, // Rotate, World X Done
            RotWorldYDone, // Rotate, World Y Done
            RotWorldZDone, // Rotate, World Z Done
            Count1, // Count1
            Count2, // Count2
            Count3, // Count3
            Count4, // Count4
            Count5, // Count5
            Count6, // Count6
            Count7, // Count7
            Count8, // Count8
            Count9, // Count9
            Count10, // Count10
            Count11, // Count11
            Count12, // Count12
            Count13, // Count13
            Count14, // Count14
            Count15, // Count15
            Count16, // Count16
            Count17, // Count17
            Count18, // Count18
            Count19, // Count19
            Count20, // Count20
            SetState, // Set State
            EnterSpongeBob, // Enter SpongeBob
            EnterPatrick, // Enter Patrick
            EnterSandy, // Enter Sandy
            EnterSandyUNUSED = EnterSandy, // Enter Sandy
            ExitSpongeBob, // Exit SpongeBob
            ExitPatrick, // Exit Patrick
            ExitSandy, // Exit Sandy
            ExitSandyUNUSED = ExitSandy, // Exit Sandy
            NPCSpecial_PlatformSnap, // NPCSpecial_PlatformSnap
            NPCSpecial_PlatformFall, // NPCSpecial_PlatformFall
            GooSetWarb, // Goo set warb coeffs
            GooSetFreezeDuration, // Goo set freeze duration
            GooMelt, // Goo melt
            SetStateRange, // Set State Range
            SetStateDelay, // Set State Delay
            SetTransitionDelay, // Set Transition Delay
            NPCFightOn, // NPC Fight On
            NPCFightOff, // NPC Fight Off
            NPCSplineOKOn, // NPC Patrol Spline On
            NPCSplineOKOff, // NPC Patrol Spline Off
            NPCKillQuietly, // NPC Kill Quietly
            HitHead, // Hit (General)
            HitUpperBody, // Hit (Head)
            HitLeftArm, // Hit (Left Arm)
            HitRightArm, // Hit (Right Arm)
            HitLeftLeg, // Hit (Left Leg)
            HitRightLeg, // Hit (Right Leg)
            HitLowerBody, // Hit (Lower Body)
            GiveCurrLevelSocks, // GiveSocks (current level)
            GiveCurrLevelPickup, // GiveCollectables (current level)
            SetCurrLevelSocks, // SetSocks (current level)
            SetCurrLevelPickup, // SetCollectables (current level)
            TalkBox_OnYes, // On Answer Yes
            TalkBox_OnNo, // On Answer No
            Hit_Cruise, // Hit Cruise Bubble
            DuploKillKids, // Duplotron_KillKids
            TalkBox_OnSignal10, // On Signal10
            TalkBox_OnSignal11, // On Signal11
            TalkBox_OnSignal12, // On Signal12
            TalkBox_OnSignal13, // On Signal13
            TalkBox_OnSignal14, // On Signal14
            TalkBox_OnSignal15, // On Signal15
            TalkBox_OnSignal16, // On Signal16
            TalkBox_OnSignal17, // On Signal17
            TalkBox_OnSignal18, // On Signal18
            TalkBox_OnSignal19, // On Signal19
            SpongeballOn, // Spongeball On
            SpongeballOff, // Spongeball Off
            LaunchShrapnel, // Launch Shrapnel
            NPCHPIncremented, // NPC HP Incremented
            NPCHPDecremented, // NPC HP Decremented
            NPCSetActiveOn, // NPC Set Active On
            NPCSetActiveOff, // NPC Set Active Off
            PlrSwitchCharacter, // Switch Player Character
            LevelBegin, // Level Begin
            SceneReset, // Scene Reset (death)
            SceneEnter, // Scene Enter
            SituationDestroyedTiki, // Destroyed Tiki
            SituationDestroyedRobot, // Destroyed Robot
            SituationSeeWoodTiki, // See Wood Tiki
            SituationSeeLoveyTiki, // See Lovey Tiki
            SituationSeeShhhTiki, // See Shhh Tiki
            SituationSeeThunderTiki, // See Thunder Tiki
            SituationSeeStoneTiki, // See Stone Tiki
            SituationSeeFodder, // See Fodder
            SituationSeeHammer, // See Hammer
            SituationSeeTarTar, // See Tar-Tar
            SituationSeeGLove, // See G-Love
            SituationSeeMonsoon, // See Monsoon
            SituationSeeSleepyTime, // See Sleepy Time
            SituationSeeArf, // See Arf
            SituationSeeTubelets, // See Tubelets
            SituationSeeSlick, // See Slick
            SituationSeeKingJellyfish, // See King Jellyfish
            SituationSeePrawn, // See Prawn
            SituationSeeDutchman, // See Dutchman
            SituationSeeSandyBoss, // See Sandy Boss
            SituationSeeSandyBossUNUSED = SituationSeeSandyBoss, // See Sandy Boss
            SituationSeePatrickBoss, // See Patrick Boss
            SituationSeeSpongeBobBoss, // See SpongeBob Boss
            SituationSeeRobotPlankton, // See Robot Plankton
            UIChangeTexture, // Change Texture of UI
            NPCCheerForMe, // NPC Cheer For Me
            FastVisible, // Fast Visible
            FastInvisible, // Fast Invisible
            ZipLineMount, // ZipLine Mount
            ZipLineDismount, // ZipLine Dismount
            Target, // Target
            Fire, // Fire
            CameraFXShake, // Camera FX Shake
            BulletTime, // Bullet Time
            Thrown, // Thrown
            UpdateAnimMatrices, // UpdateAnimMatrices
            NPCPatrol = UpdateAnimMatrices, // NPC Patrol
            EnterCruise, // EnterCruise
            ExitCruise, // ExitCruise
            CruiseFired, // CruiseFired
            CruiseDied, // CruiseDied
            CruiseAddLife, // CruiseAddLife
            CruiseSetLife, // CruiseSetLife
            CruiseResetLife, // CruiseResetLife
            CameraCollideOff, // Camera Collide Off
            CameraCollideOn, // Camera Collide On
            OnSliding, // Slide On
            OffSliding, // Slide Off
            TimerSet, // Timer Set
            TimerAdd, // Timer Add
            NPCForceConverseStart, // NPC Force Conversation
            MakeASplash, // Make A Splash
            CreditsStart, // Credits start
            CreditsStop, // Credits stop
            CreditsEnded, // Credits ended
            BubbleWipe, // Bubble Wipe
            SetLightKit, // Set Lightkit
            SetOpacity, // Set Opacity
            TakeSocksBFBB, // Take Socks
            Dispatcher_SetSoundEffect = TakeSocksBFBB, // Set Sound Effect
            DispatcherAssertBFBB, // Debug BREAK
            Scale = DispatcherAssertBFBB, // Scale
            BornBFBB, // Born
            SetReference = BornBFBB, // Set Reference
            PlatPauseBFBB, // Platform Pause
            WarpSetWorld = PlatPauseBFBB, // Warp Set World
            PlatUnpauseBFBB, // Platform Unpause
            WarpSetTask = PlatUnpauseBFBB, // Warp Set Task
            StoreOptionsBFBB, // Store Options
            WarpGo = StoreOptionsBFBB, // Warp Go
            RestoreOptionsBFBB, // Restore Options
            SetCount = RestoreOptionsBFBB, // Set Count
            GetDashSpeed, // Get Dash Speed
            DashTrip, // Dash Trip
            DashBurst, // Dash Burst
            DashFast, // Dash Fast
            DashNormal, // Dash Normal
            DashSlow, // Dash Slow
            TakeSocksNEW, // Take Socks
            DispatcherAssertNEW, // Debug BREAK
            BornNEW, // Born
            PlatPauseNEW, // Platform Pause
            PlatUnpauseNEW, // Platform Unpase
            StoreOptionsNEW, // Store Options
            RestoreOptionsNEW, // Restore Options
            UISetMotion, // UI Set Motion
            UIMotionFinished, // UI Motion Finished
            UIMotionLoop, // UI Motion Loop
            DestructibleLaunch, // Destructible launch
            DestructibleRespawn, // Destructible respawn
            KaboomStart, // Kaboom Start
            KaboomStop, // Kaboom Stop
            NPCAttack, // NPC Attack
            NPCDefend, // NPC Defend
            TrainCarSpeed, // Train Set Speed
            TrainJunctOut1, // Train Junct Out 1
            TrainJunctOut2, // Train Junct Out 2
            TrainJunctSwitch, // Train Junct Toggle
            TrainJunctPassed, // Train Junct Passed
            TrainCarDetach, // Train Car Detach
            TrainCarExplode, // Train Car Explode
            Net_InitNetAPI, // Xbox Initialize NET API
            Net_UpdateConnection, // Xbox Update Connection
            Net_UpdateOnlineTask, // Xbox Update Online Task
            Net_UpdateUserList, // Xbox Update Account List
            Net_CheckForNewContent, // Xbox Check for new content
            Net_SelectDevice, // Xbox Select Device
            Net_SelectContent, // Xbox Select Content
            Net_VerifyContent, // Xbox Verify Content
            Net_RemoveContent, // Xbox Remove Content
            Net_SelectDeviceAfterRemove, // Xbox Select Device after remove
            Net_ConfirmUseContentIdx, // Xbox Confirm use content idx
            Net_ConfirmNoUseContentIdx, // Xbox Confirm no use content idx
            Net_NoContentInstalled, // Xbox No content is installed
            Net_NoContentAvailable, // Xbox No new content is available
            Net_NewContentAvailable, // Xbox New content is available
            SceneEnableDraw, // Enable Scene Drawing
            SceneDisableDraw, // Disable Scene Drawing
            LightningStart, // Lightning Start
            LightningStop, // Lightning Stop
            ChangeBossUIStage, // Change Boss UI Stage
            StaticCameraStart, // Start static camera
            StaticCameraEnd, // End static camera
            SetCameraStartOrientation, // Set Camera Start Orientation
            NMESetMovepointPath, // NPC Set Movepoint Path
            NMEScareBegin, // NPC Scare Begin
            NMEScareSkip, // NPC Scare Skip
            NMESetMovepointGroup, // NPC Set Movepoint Group
            VentSetStateIdle, // VentSetStateIdle
            VentSetStateWarn, // VentSetStateWarn
            VentSetStateDamage, // VentSetStateDamage
            VentSetStateOff, // VentSetStateOff
            WaterhoseStart, // Waterhose Start
            WaterhoseStop, // Waterhose Stop
            WaterhoseSetLength, // Waterhose Set Length
            Carried, // Carried
            Explode, // Explode
            JumpTo, // Jump To
            JumpOnSpawn, // Jump on Spawn
            PlayerHit, // Player Hit
            StartFade, // Start Fade
            FadeDownDone, // Fade Down Done
            FadeUpDone, // Fade Up Done
            Bounce, // Bounce
            LaunchNPC, // Launch NPC
            UpgradePowerUp, // Upgrade Power Up
            BulletStreak, // Bullet Streak
            SetFollowCameraOrientation, // Set Follow Camera Orientation
            HDRFade, // High Dynamic Range Fade
            Start, // Start
            Success, // Success
            Failure, // Failure
            EnableRestore, // Enable Restore
            DisableRestore, // Disable Restore
            NPCSpawn, // NPC Spawn
            SpawnDone, // NPC Spawn Done
            SpawnedNPCKilled, // Spawned NPC Killed
            SpawnedNPCNoHealth, // Spawned NPC No Health
            SpawnedNPCAllKilled, // Spawned NPCs All Killed
            SpawnedNPCAllNoHealth, // Spawned NPCs All No Health
            DashTimerSet, // Set Dash Timer
            DashNotOutOfTime, // Dash Not Out of Time
            DashOutOfTime, // Dash Out of Time
            ForceSceneReset, // Force Scene Reset
            NPCActive, // NPC Active
            NPCInactive, // NPC Inactive
            DuplicatorActive, // Duplicator Active
            DuplicatorInactive, // Duplicator Deactivate
            DashEnterTunnel, // Dash Enter Tunnel
            DashExitTunnel, // Dash Exit Tunnel
            StopRumbleEffect, // StopRumbleEffect
            DashChaseLasersOn, // Dash Chase Lasers On
            DashChaseLasersOff, // Dash Chase Lasers Off
            JumpRandomOnSpawn, // Random Jump on Spawn
            Hit_Cartwheel, // Hit Patrick Cartwheel
            UIVisible_FocusOn_Select, // UI Visible+Focus On+Select
            UIFocusOff_Unselect_Invisible, // UI Focus Off+Unselect+Invisible
            CopyReference, // Copy Reference
            UIMotionFinishedIn, // UI Motion In Finished
            UIMotionFinishedOut, // UI Motion Out Finished
            UISignalActivateScreen, // UI Signal Activate Screen
            UISignalDeactivateScreen, // UI Signal Deactivate Screen
            UISignalActivatedScreen, // UI Signal Activated Screen
            UISignalSwitchScreens, // UI Signal Switch Screens
            UISignalStartFadeOut, // UI Signal Start Fade Out
            UISignalStartFadeIn, // UI Signal Start Fade In
            UISignalScreenMotionInDone, // UI Signal Screen Motion In Done
            UISignalScreenMotionOutDone, // UI Signal Screen Motion Out Done
            UISignalMainBoxInDone, // UI Signal Main Box In Done
            UISignalMainBoxOutDone, // UI Signal Main Box Out Done
            UIResetMotion, // UI Reset Motion
            UIEnableHDR, // UI Enable HDR
            UIDisableHDR, // UI Disable HDR
            UIBrighten, // UI Brighten
            UIUnbrighten, // UI Unbrighten
            UISignalDeactivatedScreen, // UI Signal Deactivated Screen
            NPCDetectAlways, // NPC Detect Always
            NPCDetectNever, // NPC Detect Never
            NPCDetectNormal, // NPC Detect Normal
            NPCFightDefault, // NPC Fight Default
            CameraCollidePartial, // Camera Collide Partial
            MusicTempSong, // MusicTrack Play Temporary
            EvaluateCounterValue, // Evaluate Counter Value
            Count0, // Count0
            RotToAbsoluteX, // Rotate to Absolute X
            RotToAbsoluteY, // Rotate to Absolute Y
            RotToAbsoluteZ, // Rotate to Absolute Z
            TriggerAnim, // Play Trigger Animation
            TriggeredAnimDone, // Triggered Animation Done
            UISignalMore, // UI Signal More
            UISignalNoMore, // UI Signal No More
            UISignalLess, // UI Signal Less
            UISignalNoLess, // UI Signal No Less
            UISignalUp, // UI Signal Up
            UISignalDown, // UI Signal Down
            UISignalSyncToCurrent, // UI Signal Sync To Current
            UISignalEffect, // UI Signal Effect
            FreezePlayer, // Freeze Player
            UnfreezePlayer, // Unfreeze Player
            UISignalMapStart, // UI Signal Map Start
            UISignalMapEnd, // UI Signal Map End
            TransToAbsoluteX, // Translate to Absolute X
            TransToAbsoluteY, // Translate to Absolute Y
            TransToAbsoluteZ, // Translate to Absolute Z
            JSPVisibilityIncrement, // JSP Visibility Increment
            JSPVisibilityDecrement, // JSP Visibility Decrement
            EnterCamera, // Enter Camera
            ExitCamera, // Exit Camera
            PadPressE, // PadPressE (GC Z or XBOX Black)
            SetDashJumpParameters, // Dash Set Jump Parameters
            ViperFacePlayer, // Viper Face Player
            ViperFaceMovement, // Viper Face Movement
            RequestStart, // RequestStart
            UIAutoMenuRun, // UI Auto Menu Run
            UIAutoMenuRunUp, // UI Auto Menu Run Up
            UIAutoMenuRunDown, // UI Auto Menu Run Down
            UIAutoMenuRunLeft, // UI Auto Menu Run Left
            UIAutoMenuRunRight, // UI Auto Menu Run Right
            IncrementSuccess, // Increment Success
            DecrementSuccess, // Decrement Success
            IncrementFailed, // Increment Failed
            DecrementFailed, // Decrement Failed
            MusicTempSongStop, // MusicTrack Stop Temporary Music
            NPCScrambleActionBegin, // NPC Scramble Action Begin
            NPCScrambleAlert, // NPC Scramble Alert
            NPCSetTurretAttackRadius, // NPC Turret Set Attack Radius
            GooFreezeStart, // Goo Freeze Start
            GooMeltStart, // Goo Melt Start
            NPCNotice, // NPC Notice
            BossStageSet, // Boss Stage Set
            BossStageBegan, // Boss Stage Began
            BossStageEnded, // Boss Stage Ended
            BossStageBeganA, // Boss Stage A Began
            BossStageEndedA, // Boss Stage A Ended
            BossStageBeganB, // Boss Stage B Began
            BossStageEndedB, // Boss Stage B Ended
            BossStageBeganC, // Boss Stage C Began
            BossStageEndedC, // Boss Stage C Ended
            VisibilityCullOn, // Visibility Cull On
            VisibilityCullOff, // Visibility Cull Off
            RBandCameraStart, // Start rband camera
            RBandCameraEnd, // End rband camera
            MindyStart, // Mindy Start
            MindyEnd, // Mindy End
            FlamethrowerStart, // Flamethrower Start
            FlamethrowerStop, // Flamethrower Stop
            FlamethrowerSetLength, // Flamethrower Set Length
            NPCTakeNoDamageOn, // NPC Take No Damage On
            NPCTakeNoDamageOff, // NPC Take No Damage Off
            StaticCameraStartFOVFilter, // Start StaticCAM FOV filter
            StaticCameraRestoreFOV, // Restore StaticCAM FOV
            UIXboxDemoExitToLauncher, // XBOX DEMO exit to launcher
            Spawn, // Spawn
            Spawned, // Spawned
            CreditsSetDest, // Credits set dest
            AllowAttractMode, // Allow Attact Mode
            DisallowAttractMode, // Disallow Attract Mode
            RocketAttack, // Rocket Attack
            CollisionReset, // Collision Reset
            AutoSave, // AutoSave
            OpenBonus, // Open Bonus
            FlagLevel, // Flag Level
            LevelEnd, // Level End
            Net_GetLocalContentDevice, // Get Local Content
            Dispatcher_PauseGame_Safe, // Pause Game Safe
            OverrideFreqency, // Override Frequency
            ResetFrequency, // Reset Frequency
            SetShotDelay, // Set Shot Delay
            SetShotsInGroup, // Set Shots In Group
            Dispatcher_UserSelectYes, // User Select Yes
            Dispatcher_UserSelectNo, // User Select No
            Dispatcher_UserSelectBack, // User Select Back
            LaunchFireWorks, // Launch Fire Works
            Dispatcher_UserSelectionReset, // Resets user selection
            SetAsBounceBack, // Set as Bounce Back
            UIResetUnlockables, // Reset Unlockables
            UISysMessageWaitResponse, // UI Sys Msg Wait Response
            UISysMessageWaitConfirm, // UI Sys Msg Wait Confirm
            UISysMessageConfirm, // UI Sys Msg Confirm
            UISysMessageAccept, // UI Sys Msg Accept
            UISysMessageDecline, // UI Sys Msg Decline
            SetAsBounceBack_Cancel, // Set as NOT Bounce Back
            Dispatcher_PauseGame, // Pause Game Now
            PattyWagonStartEngine, // Patty Wagon Start Engine
            PattyWagonStopEngine, // Patty Wagon Stop Engine
            SpawnBubblesOn, // Bubble Spawn On
            SpawnBubblesOff, // Bubble Spawn Off
            Net_XBLiveToggleSignIn, // XBLive Toggle Sign In
            Net_XBLiveManageFriends, // XBLive Manage Friends
            ApplyOnResetOn, // Apply On Reset - On
            ApplyOnResetOff, // Apply On Reset - Off
            SnapTo, // Snap To
            Throw, // Throw
            FirstZipLine, // First Zip Line
            FirstLedgeGrab, // First Ledge Grab
            FirstIncredimeterPickup, // First Incredimeter Pickup
            UISparkTrail, // UI Spark Trail
            UIGetBattleScenes, // UI Get Battle Scenes
            UIBattleScenesAvailable, // UI Battle Scenes Available
            UIBattleScenesNotAvailable, // UI Battle Scenes Not Available
            Net_XBLiveToggleAppearOnline, // XBLive Toggle Appear Online
            Sys_ReturnPrevScreen, // UI Return to previous screen
            Sys_Nope, // UI Empty Event
            Dispatcher_SubtitlesOn, // Subtitles Enabled
            Dispatcher_SubtitlesOff, // Subtitles Disabled
            UISetBoxMapping, // UI Set Box Mapping for UVs
            TBoxPlayerEjected, // Player Ejected
            DamagePlayer, // Damage Player
            FirstHealthPickup, // First Health Pickup
            TokenPickupComplete, // Token Pickup Complete
            Dispatcher_LoadSavePromptDead, // Prompt is dead
            UIFlipVisibility, // UI Flip Visibility
            Net_XBLiveRebootToDashboard, // XBLive Reboot To Dashboard
            FirstPowerupPoint, // First Powerup Point
            UIIsBattleScene, // UI Is Battle Scene
            UIBattleSceneYes, // UI Battle Scene Yes
            UIBattleSceneNo, // UI Battle Scene No
            UILockElement, // UI Lock element
            UIUnlockElement, // UI Unlock element
            DrivenbyOff, // Drivenby Off
            DrivenbyOn, // Drivenby On
            UISignalCreditCode, // UI Signal Credit Code
            UISignalHILogo, // UI Signal HI Logo
            DisableAutoSave, // Disable Auto Save
            UISignalEnlargeWindow, // UI Signal Enlarge Window
            Dispatcher_LoadSavePromptExiting, // Prompt Exiting
            Dispatcher_LoadSavePromptForceExit, // Prompt Force Exit
            Sys_ActionConfirmed, // UI Sys Message Action Confirmed
            Sys_ActionDeclined // UI Sys Message Action Declined
        };

    }

}