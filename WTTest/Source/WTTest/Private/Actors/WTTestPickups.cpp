// Fill out your copyright notice in the Description page of Project Settings.

// --------- WTTest Includes ------------
#include "Actors/WTTestPickups.h"

// Sets default values
AWTTestPickups::AWTTestPickups(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	m_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent= m_Mesh;

	SetPowerup();
}

void AWTTestPickups::BeginPlay()
{
	Super::BeginPlay();	

}

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