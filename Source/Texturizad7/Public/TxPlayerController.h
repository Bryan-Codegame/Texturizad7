// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TxPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TEXTURIZAD7_API ATxPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnMissionCompleted(APawn* InstigatorPawn, bool isMissionSuccess);
};
