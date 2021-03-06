// Fill out your copyright notice in the Description page of Project Settings.



// --------- Engine Includes ------------
#include "Actors/WTTestDestructibleWall.h"
#include "Actors/WTTestPickups.h"
#include "GameModes/WTTestGameMode.h"


// Sets default values
AWTTestDestructibleWall::AWTTestDestructibleWall(const FObjectInitializer& ObjectInitializer): 
	Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMeshComponent"));

	RootComponent = m_CubeMesh;
}

void AWTTestDestructibleWall::Tick(float DeltaTime) 
{
  Super::Tick(DeltaTime);
}

void AWTTestDestructibleWall::ProcessWallDestruction()
{
  FActorSpawnParameters spawnParameters;
  spawnParameters.Instigator = GetInstigator();

  int32 spawning = FMath::RandRange(1, m_PickUpSpawningRatio);
  if (spawning == m_PickUpSpawningRatio)
  {
    AWTTestPickups* pickup =
      GetWorld()->SpawnActor<AWTTestPickups>(m_Pickup, GetActorLocation(), GetActorRotation(), spawnParameters);

    AWTTestGameMode* gm = Cast<AWTTestGameMode>(GetWorld()->GetAuthGameMode());
    gm->m_MapManager->SetGridValueWithActorLocation(GetActorLocation(), (int32)GridData::kPickups);
  }
}


