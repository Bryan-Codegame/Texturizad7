// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Texturizad7GameMode.generated.h"

UCLASS(minimalapi)
class ATexturizad7GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATexturizad7GameMode();

	void CompleteMission(APawn* Pawn, bool isMissionSuccess);

	UFUNCTION(BlueprintImplementableEvent, Category="GameMode")
	void OnMissionComplete(APawn* Pawn, bool isMissionSuccess);
};



