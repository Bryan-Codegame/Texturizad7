// Fill out your copyright notice in the Description page of Project Settings.


#include "TxGameStateBase.h"

#include "EngineUtils.h"
#include "TxPlayerController.h"

void ATxGameStateBase::MulticastOnMissionComplete_Implementation(APawn* InstigatorPawn, bool bMissionSuccess)
{
	/*for(TActorIterator<APawn> It(GetWorld()); It; ++It)
	{
		APawn* Pawn = *It;
		if(Pawn && Pawn->IsLocallyControlled())
		{
			Pawn->DisableInput(nullptr);
		}
	}*/

	/*if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		if(APawn* Pawn = PC->GetPawn())
		{
			Pawn->DisableInput(nullptr);
		}
	}*/


	//ITERATE PLAYER CONTROLLER - WITH ITERATOR
	/*for(FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; It++)
	{
		ATxPlayerController* PC = Cast<ATxPlayerController>(It->Get());
		if(PC && PC->IsLocalController())
		{
			PC->OnMissionCompleted(InstigatorPawn, bMissionSuccess);
		}

		if(APawn* Pawn = PC->GetPawn())
		{
			Pawn->DisableInput(nullptr);
		}
	}*/

	//ITERATE PLAYER CONTROLLER - WITHOUT ITERATOR
	if (ATxPlayerController* PC = Cast<ATxPlayerController>(GetWorld()->GetFirstPlayerController()))
	{
		PC->OnMissionCompleted(InstigatorPawn, bMissionSuccess);
		if(APawn* Pawn = PC->GetPawn())
		{
			Pawn->DisableInput(nullptr);
		}
	}

	
}
