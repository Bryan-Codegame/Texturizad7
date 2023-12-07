// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectiveZone.h"

#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Texturizad7/Texturizad7Character.h"
#include "Texturizad7/Texturizad7GameMode.h"

// Sets default values
AObjectiveZone::AObjectiveZone():
	SizeBoxAndDecal(200.0f)
{
 	
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));

	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComp->SetCollisionResponseToChannels(ECR_Ignore);
	OverlapComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	OverlapComp->SetBoxExtent(FVector(SizeBoxAndDecal));

	RootComponent = OverlapComp;

	OverlapComp->SetHiddenInGame(false);

	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::HandleOverlap);

	//Decal
	DecalComp = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComp"));
	DecalComp->DecalSize = FVector(SizeBoxAndDecal);
	DecalComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AObjectiveZone::BeginPlay()
{
	Super::BeginPlay();
	
}

void AObjectiveZone::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	UE_LOG(LogTemp, Log, TEXT("Overlapped"));

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green,
			FString::Printf(TEXT("Overlapped")));
	}

	ATexturizad7Character* MyPawn = Cast<ATexturizad7Character>(OtherActor);
	if (MyPawn == nullptr)
		return;

	if (MyPawn->bIsCarryingObjective)
	{
		ATexturizad7GameMode* GM = Cast<ATexturizad7GameMode>(GetWorld()->GetAuthGameMode());
		if(GM)
		{
			GM->CompleteMission(MyPawn, true);
		}
	}
	else
	{
		UGameplayStatics::PlaySound2D(this, ObjectMissingSound);
	}
	
}


