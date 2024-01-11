// Copyright Epic Games, Inc. All Rights Reserved.

#include "Texturizad7GameMode.h"
#include "Texturizad7Character.h"
#include "TxGameStateBase.h"
#include "UObject/ConstructorHelpers.h"

ATexturizad7GameMode::ATexturizad7GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	GameStateClass = ATxGameStateBase::StaticClass();

}

void ATexturizad7GameMode::CompleteMission(APawn* Pawn, bool isMissionSuccess)
{
	/*if(Pawn)
	{
		Pawn->DisableInput(nullptr);
	}*/

	ATxGameStateBase* GS = GetGameState<ATxGameStateBase>();

	if (GS)
	{
		GS->MulticastOnMissionComplete(Pawn, isMissionSuccess);
	}
	
	OnMissionComplete(Pawn, isMissionSuccess);
}
