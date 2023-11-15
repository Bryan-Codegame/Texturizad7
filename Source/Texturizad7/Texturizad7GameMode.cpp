// Copyright Epic Games, Inc. All Rights Reserved.

#include "Texturizad7GameMode.h"
#include "Texturizad7Character.h"
#include "UObject/ConstructorHelpers.h"

ATexturizad7GameMode::ATexturizad7GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

void ATexturizad7GameMode::CompleteMission(APawn* Pawn)
{
	if(Pawn)
	{
		Pawn->DisableInput(nullptr);
	}

	OnMissionComplete(Pawn);
}
