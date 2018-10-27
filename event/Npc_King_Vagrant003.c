-------- EventFlow: Npc_King_Vagrant003 --------

Actor: EventSystemActor
entrypoint: None()
actions: ['Demo_FlagON', 'Demo_WaitFrame', 'Demo_AutoSave']
queries: ['CheckFlag', 'RandomChoice2', 'CheckTimeType', 'GeneralChoice2', 'CheckGameDataInt']
params: {'CreateMode': 0, 'IsGrounding': False, 'IsWorld': False, 'PosX': 0.0, 'PosY': 0.0, 'PosZ': 0.0, 'RotX': 0.0, 'RotY': 0.0, 'RotZ': 0.0}

Actor: Npc_King_Vagrant003
entrypoint: None()
actions: ['Demo_TalkASync', 'Demo_Talk', 'Demo_ForbidSettingInstEventFlag']
queries: ['IsOnInstEventFlag']
params: {'CreateMode': 0, 'IsGrounding': False, 'IsWorld': False, 'PosX': 0.0, 'PosY': 0.0, 'PosZ': 0.0, 'RotX': 0.0, 'RotY': 0.0, 'RotZ': 0.0}

void Near() {
    if EventSystemActor.CheckFlag({'FlagName': 'Npc_King_Vagrant003_Talk'}) {
        if !EventSystemActor.RandomChoice2() {
            Npc_King_Vagrant003.Demo_TalkASync({'MessageId': 'EventFlowMsg/Npc_King_Vagrant003:Near01', 'IsWaitFinish': True, 'IsChecked': False, 'DispFrame': 90})
        } else {
            Event2:
            Npc_King_Vagrant003.Demo_TalkASync({'MessageId': 'EventFlowMsg/Npc_King_Vagrant003:Near00', 'IsWaitFinish': True, 'IsChecked': False, 'DispFrame': 90})
        }
    } else {
        goto Event2
    }
}

void Talk() {

    call InitTalk.InitTalk({'Arg_Turn': 0, 'Arg_Greeting': 'FollowAISchedule'})

    if Npc_King_Vagrant003.IsOnInstEventFlag() {
        Event127:
        if EventSystemActor.CheckFlag({'FlagName': 'Npc_King_Vagrant003_Talk'}) {
            Event107:
            if EventSystemActor.CheckFlag({'FlagName': 'Dungeon_Clear_1'}) {
                Npc_King_Vagrant003.Demo_Talk({'MessageId': 'EventFlowMsg/Npc_King_Vagrant003:Talk06', 'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False})
                Event142:
                if EventSystemActor.CheckFlag({'FlagName': 'Get_Vagrant_BOKANGI'}) {
                    if Npc_King_Vagrant003.IsOnInstEventFlag() {
                        Event132:
                        Npc_King_Vagrant003.Demo_Talk({'IsWaitFinish': True, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_King_Vagrant003:Nagameru01', 'IsCloseMessageDialog': True})
                        Event172:
                        if !EventSystemActor.CheckFlag({'FlagName': 'Get_Vagrant_BOKANGI'}) {
                            EventSystemActor.Demo_WaitFrame({'Frame': 20, 'IsWaitFinish': True})

                            call GoodBye()

                        }
                    } else {
                        Event157:

                        call GoodBye()

                    }
                } else {
                    goto Event157
                }
            } else {
                Npc_King_Vagrant003.Demo_Talk({'MessageId': 'EventFlowMsg/Npc_King_Vagrant003:Talk05', 'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False})
                goto Event142
            }
        } else {
            Npc_King_Vagrant003.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_King_Vagrant003:Talk01'})
            Event146:
            if !EventSystemActor.GeneralChoice2() {
                Npc_King_Vagrant003.Demo_Talk({'MessageId': 'EventFlowMsg/Npc_King_Vagrant003:Nagameru00', 'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'ASName': 'Point'})
                if EventSystemActor.CheckFlag({'FlagName': 'Npc_King_Vagrant006_Talk'}) {
                    EventSystemActor.Demo_FlagON({'IsWaitFinish': True, 'FlagName': 'Npc_King_Vagrant003_Talk'})
                    Npc_King_Vagrant003.Demo_ForbidSettingInstEventFlag({'IsWaitFinish': True})
                    goto Event132
                } else {
                    Npc_King_Vagrant003.Demo_Talk({'MessageId': 'EventFlowMsg/Npc_King_Vagrant006:FirstTalk10', 'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False})

                    call OperationGuide.Guide_Scope()

                    Npc_King_Vagrant003.Demo_Talk({'MessageId': 'EventFlowMsg/Npc_King_Vagrant006:FirstTalk11', 'IsWaitFinish': True, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'IsCloseMessageDialog': False})
                    if !EventSystemActor.GeneralChoice2() {
                        if EventSystemActor.CheckFlag({'FlagName': 'Npc_King_Vagrant006_Talk_ToshinoKou'}) {
                            Npc_King_Vagrant003.Demo_Talk({'IsWaitFinish': True, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'IsCloseMessageDialog': False, 'MessageId': 'EventFlowMsg/Npc_King_Vagrant006:FirstTalk13'})
                            Event153:
                            Npc_King_Vagrant003.Demo_Talk({'IsWaitFinish': True, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'IsCloseMessageDialog': True, 'MessageId': 'EventFlowMsg/Npc_King_Vagrant006:FirstTalk14'})
                            EventSystemActor.Demo_FlagON({'IsWaitFinish': True, 'FlagName': 'Npc_King_Vagrant003_Talk'})
                            Npc_King_Vagrant003.Demo_ForbidSettingInstEventFlag({'IsWaitFinish': True})
                            goto Event172
                        } else {
                            Npc_King_Vagrant003.Demo_Talk({'IsWaitFinish': True, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'IsCloseMessageDialog': False, 'MessageId': 'EventFlowMsg/Npc_King_Vagrant006:FirstTalk12'})
                            EventSystemActor.Demo_FlagON({'IsWaitFinish': True, 'FlagName': 'Npc_King_Vagrant006_Talk_ToshinoKou'})
                            goto Event153
                        }
                    } else {
                        goto Event153
                    }
                }
            } else {
                Event92:
                if EventSystemActor.CheckFlag({'FlagName': 'Get_Vagrant_BOKANGI'}) {
                    if EventSystemActor.CheckGameDataInt({'GameDataIntName': 'DungeonClearCounter', 'Value': 3, 'Operator': 'GreaterThanOrEqualTo'}) {
                        Npc_King_Vagrant003.Demo_Talk({'IsWaitFinish': True, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'IsCloseMessageDialog': True, 'MessageId': 'EventFlowMsg/Npc_King_Vagrant006:GoodBye03'})
                    } else {
                        if EventSystemActor.CheckGameDataInt({'GameDataIntName': 'DungeonClearCounter', 'Operator': 'GreaterThanOrEqualTo', 'Value': 1}) {
                            Npc_King_Vagrant003.Demo_Talk({'IsWaitFinish': True, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'IsCloseMessageDialog': True, 'MessageId': 'EventFlowMsg/Npc_King_Vagrant003:GoodBye01'})
                        } else {
                            Npc_King_Vagrant003.Demo_Talk({'IsWaitFinish': True, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'IsCloseMessageDialog': True, 'MessageId': 'EventFlowMsg/Npc_King_Vagrant003:GoodBye00'})
                        }
                    }
                } else {
                    Npc_King_Vagrant003.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_King_Vagrant003:GoodBye04'})
                    EventSystemActor.Demo_FlagON({'IsWaitFinish': True, 'FlagName': 'Npc_King_Vagrant003_BOKANGI'})

                    call Npc_King_Common.BOKANGI_Get({'Self': ActorIdentifier(name="Npc_King_Vagrant003")})

                    EventSystemActor.Demo_AutoSave({'IsWaitFinish': True})
                }
            }
        }
    } else {
        switch EventSystemActor.CheckTimeType() {
          case 0:
            Npc_King_Vagrant003.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_King_Vagrant003:Talk02'})
            if EventSystemActor.CheckFlag({'FlagName': 'Npc_King_Vagrant003_Talk'}) {
                goto Event107
            } else {
                Event76:
                Npc_King_Vagrant003.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_King_Vagrant003:Talk00'})
                goto Event146
            }
          case 1:
            Event163:
            if EventSystemActor.CheckFlag({'FlagName': 'Npc_King_Vagrant003_Talk'}) {
                Npc_King_Vagrant003.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_King_Vagrant003:Talk08'})
                goto Event107
            } else {
                goto Event76
            }
          case 2:
            goto Event163
          case 3:
            goto Event163
          case 4:
            goto Event163
          case 5:
            goto Event163
          case 6:
            Event21:
            Npc_King_Vagrant003.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_King_Vagrant003:Talk03'})
            goto Event127
          case 7:
            goto Event21
        }
    }
}

void GoodBye() {
    goto Event92
}