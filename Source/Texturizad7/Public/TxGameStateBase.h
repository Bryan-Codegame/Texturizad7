// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TxGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class TEXTURIZAD7_API ATxGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	UFUNCTION(NetMulticast, Reliable)
	void MulticastOnMissionComplete(APawn* InstigatorPawn, bool bMissionSuccess);
};
