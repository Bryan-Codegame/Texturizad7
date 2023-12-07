// Fill out your copyright notice in the Description page of Project Settings.


#include "AIEnemy.h"

#include "Perception/PawnSensingComponent.h"
#include "Texturizad7/Texturizad7GameMode.h"

// Sets default values
AAIEnemy::AAIEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	
}

// Called when the game starts or when spawned
void AAIEnemy::BeginPlay()
{
	Super::BeginPlay();
	OriginalRotator = GetActorRotation();
}

void AAIEnemy::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	PawnSensingComp->OnSeePawn.AddDynamic(this, &ThisClass::OnPawnSeen);
	PawnSensingComp->OnHearNoise.AddDynamic(this, &ThisClass::OnNoiseHear);
}

void AAIEnemy::OnPawnSeen(APawn* SeenPawn)
{
	if (SeenPawn == nullptr)
	{
		return;
	}

	DrawDebugSphere(GetWorld(), SeenPawn->GetActorLocation(), 32.0f, 12,
		FColor::Magenta, false, 10.0f);

	ATexturizad7GameMode* GM = Cast<ATexturizad7GameMode>(GetWorld()->GetAuthGameMode());
	if(GM)
	{
		GM->CompleteMission(SeenPawn, false);
	}
}

void AAIEnemy::OnNoiseHear(APawn* PawnInstigator, const FVector& Location, float Volume)
{
	DrawDebugSphere(GetWorld(), Location, 32.0f, 12,
		FColor::Green, false, 10.0f);

	FVector Direction = Location - GetActorLocation();
	Direction.Normalize();

	FRotator NewLookAt = FRotationMatrix::MakeFromX(Direction).Rotator();
	NewLookAt.Pitch = 0.0f;
	NewLookAt.Roll = 0.0f;

	SetActorRotation(NewLookAt);

	GetWorldTimerManager().ClearTimer(TimerHandle_ResetOrientation);
	GetWorldTimerManager().SetTimer(TimerHandle_ResetOrientation, this, &AAIEnemy::ResetOrientation, 3.0f);
	
}

void AAIEnemy::ResetOrientation()
{
	SetActorRotation(OriginalRotator);
}

// Called every frame
void AAIEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAIEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

