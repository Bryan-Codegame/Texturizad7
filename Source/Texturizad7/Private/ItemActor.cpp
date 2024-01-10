// Fill out your copyright notice in the Description page of Project Settings.


#include "Texturizad7/Public/ItemActor.h"

#include "Kismet/GameplayStatics.h"
#include "Texturizad7/Texturizad7Character.h"


// Sets default values
AItemActor::AItemActor()
{

	//bReplicates = true;
	
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetupAttachment(MeshComp);

	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

// Called when the game starts or when spawned
void AItemActor::BeginPlay()
{
	Super::BeginPlay();
}

void AItemActor::PlayEffects()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, PickupFX, GetActorLocation());
}

void AItemActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	PlayEffects();

	/*if (HasAuthority())
	{
		ATexturizad7Character* MyCharacter = Cast<ATexturizad7Character>(OtherActor);

		if (MyCharacter)
		{
			MyCharacter->bIsCarryingObjective = true;
			Destroy();
		}	
	}*/

	ATexturizad7Character* MyCharacter = Cast<ATexturizad7Character>(OtherActor);

	if (MyCharacter)
	{
		MyCharacter->bIsCarryingObjective = true;
		Destroy();
	}	
	
}

