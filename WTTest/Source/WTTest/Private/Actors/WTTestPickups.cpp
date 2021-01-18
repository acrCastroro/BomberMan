// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/WTTestPickups.h"

// Sets default values
AWTTestPickups::AWTTestPickups(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent= m_Mesh;

	SetPowerup();

}

// Called when the game starts or when spawned
void AWTTestPickups::BeginPlay()
{
	Super::BeginPlay();	

}

// Called every frame
void AWTTestPickups::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWTTestPickups::SetPowerup()
{
	int32 maxRange = (int32)PickupTypes::kMax - 1;
	m_PickupType = (PickupTypes)FMath::RandRange((int32)PickupTypes::kAddBomb, maxRange);

}


PickupTypes AWTTestPickups::GetPickupType()
{
	return m_PickupType;
}