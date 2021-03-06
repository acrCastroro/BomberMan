// Fill out your copyright notice in the Description page of Project Settings.



// --------- Engine Includes ------------
#include "Actors/WTTestBomb.h"
#include "Actors/WTTestBombExplosion.h"
#include "Actors/WTTestDestructibleWall.h"
#include "Characters/WTTestCharacter.h"
#include "GameModes/WTTestGameMode.h"
// --------- Engine Includes ------------
#include "Kismet/GameplayStatics.h"


AWTTestBomb::AWTTestBomb(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	m_SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	RootComponent = m_SphereMesh;

	m_SpawnParameters.Instigator = GetInstigator();
	m_SpawnParameters.Owner = this;
}

// Called when the game starts or when spawned
void AWTTestBomb::BeginPlay()
{
	Super::BeginPlay();

	UWorld* world = GetWorld();
	check(IsValid(world));

	m_GameMode = Cast<AWTTestGameMode>(world->GetAuthGameMode());

	m_Owner = Cast<AWTTestCharacter>(GetOwner());
	check(IsValid(m_Owner));
	
	if (IsValid(world)) 
	{
		world->GetTimerManager().SetTimer(m_TimeToExplodeHandle, this, &AWTTestBomb::Explode, m_TimeToExplode, false);
    world->GetTimerManager().SetTimer(m_TimeToGrowHandle, this, &AWTTestBomb::Grow, m_TimeToGrow, true);
	}	
}

// Called every frame
void AWTTestBomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWTTestBomb::Explode()
{
  m_bActive = true;
	m_Owner->m_NumberOfAvailableBombs++;

	CheckExplosionsExpansions();

	Destroy();

	SpawnCentralExplosion();
}

void AWTTestBomb::Grow()
{
  m_SphereMesh->SetRelativeScale3D(m_SphereMesh->GetRelativeScale3D() + FVector(.05f));
}

void AWTTestBomb::UpExplosionExpansion()
{

	int32 xGridPosition = 0;
	int32 yGridPosition = 0;
	auto grid = m_GameMode->m_MapManager;
	grid->GetGridValueWithLocation(GetActorLocation(), xGridPosition, yGridPosition);

	int32 gridDisplacement = 0;
	int32 positionToCheck = xGridPosition - 1;

	while (gridDisplacement < m_Owner->m_CurrentExplosionTileDistance)
	{

		if (positionToCheck < 0 || positionToCheck >= grid->m_kGridHeight) break;

		int32 aux = grid->GetGridValue(positionToCheck, yGridPosition);

		if (aux == (int32)GridData::kDestructibleWall) {
      DestroyWallAtGridPosition(positionToCheck, yGridPosition);
			break;
		}
		else if (aux == (int32)GridData::kIndesttructibleWall)
		{
			break;
		}
		else if (aux == (int32)GridData::kPickups)
		{
			grid->DestroyActorFromGrid(positionToCheck, yGridPosition);
		}
		else if (aux == (int32)GridData::kExplosion)
		{
			break;
		}
		
		FVector spawnLocation =	grid->GetWorldPositionFromGrid(positionToCheck, yGridPosition);

		grid->SetGridValueWithActorLocation(spawnLocation, (int32)GridData::kExplosion);

		AWTTestBombExplosion* spawnedExplosion =
			GetWorld()->SpawnActor<AWTTestBombExplosion>(m_BombExplosion, spawnLocation, FRotator(-80.0f), m_SpawnParameters);
	
		gridDisplacement++;
		positionToCheck--;
	}

}

void AWTTestBomb::RightExplosionExpansion()
{

	int32 xGridPosition = 0;
	int32 yGridPosition = 0;
	auto grid = m_GameMode->m_MapManager;
	grid->GetGridValueWithLocation(GetActorLocation(), xGridPosition, yGridPosition);

	int32 gridDisplacement = 0;
	int32 positionToCheck = yGridPosition + 1;
	while (gridDisplacement < m_Owner->m_CurrentExplosionTileDistance)
	{

		if (positionToCheck < 0 || positionToCheck >= grid->m_kGridWidth) break;

		int32 aux = grid->GetGridValue(xGridPosition, positionToCheck);

		if (aux == (int32)GridData::kDestructibleWall) 
    {
      DestroyWallAtGridPosition(xGridPosition, positionToCheck);
			break;
		}
		else if (aux == (int32)GridData::kIndesttructibleWall)
		{
			break;
		}
		else if (aux == (int32)GridData::kPickups)
		{
			grid->DestroyActorFromGrid(xGridPosition, positionToCheck);
		}
		else if (aux == (int32)GridData::kExplosion)
		{
			break;
		}
		
		FVector spawnLocation = grid->GetWorldPositionFromGrid(xGridPosition, positionToCheck);

		grid->SetGridValueWithActorLocation(spawnLocation, (int32)GridData::kExplosion);

		AWTTestBombExplosion* spawnedExplosion =
			GetWorld()->SpawnActor<AWTTestBombExplosion>(m_BombExplosion, spawnLocation, FRotator(-80.0f), m_SpawnParameters);

		gridDisplacement++;
		positionToCheck++;
	}
}

void AWTTestBomb::DownExplosionExpansion()
{

	int32 xGridPosition = 0;
	int32 yGridPosition = 0;
	auto grid = m_GameMode->m_MapManager;
	grid->GetGridValueWithLocation(GetActorLocation(), xGridPosition, yGridPosition);

	int32 gridDisplacement = 0;
	int32 positionToCheck = xGridPosition + 1;

	while (gridDisplacement < m_Owner->m_CurrentExplosionTileDistance)
	{

		if (positionToCheck < 0 || positionToCheck >= grid->m_kGridHeight) break;

		int32 aux = grid->GetGridValue(positionToCheck, yGridPosition);

		if (aux == (int32)GridData::kDestructibleWall) 
    {
      DestroyWallAtGridPosition(positionToCheck, yGridPosition);
			break;
		}
		else if (aux == (int32)GridData::kIndesttructibleWall)
		{
			break;
		}
		else if (aux == (int32)GridData::kPickups)
		{
			grid->DestroyActorFromGrid(positionToCheck, yGridPosition);
		}
		else if (aux == (int32)GridData::kExplosion)
		{
			break;
		}
		
		FVector spawnLocation =	grid->GetWorldPositionFromGrid(positionToCheck, yGridPosition);

	    grid->SetGridValueWithActorLocation(spawnLocation, (int32)GridData::kExplosion);

		AWTTestBombExplosion* spawnedExplosion =
			GetWorld()->SpawnActor<AWTTestBombExplosion>(m_BombExplosion, spawnLocation, FRotator(-80.0f), m_SpawnParameters);

		gridDisplacement++;
		positionToCheck++;
	}
}

void AWTTestBomb::LeftExplosionExpansion()
{
	int32 xGridPosition = 0;
	int32 yGridPosition = 0;
	auto grid = m_GameMode->m_MapManager;
	grid->GetGridValueWithLocation(GetActorLocation(), xGridPosition, yGridPosition);

	int32 gridDisplacement = 0;
	int32 positionToCheck = yGridPosition - 1;

	while (gridDisplacement < m_Owner->m_CurrentExplosionTileDistance)
	{

		if (positionToCheck < 0 || positionToCheck >= grid->m_kGridWidth) break;

		int32 aux = grid->GetGridValue(xGridPosition, positionToCheck);

		if (aux == (int32)GridData::kDestructibleWall) 
    {
      DestroyWallAtGridPosition(xGridPosition, positionToCheck);
			break;
		}
		else if (aux == (int32)GridData::kIndesttructibleWall)
		{
			break;
		}
		else if (aux == (int32)GridData::kPickups)
		{
			grid->DestroyActorFromGrid(xGridPosition, positionToCheck);
		}
		else if (aux == (int32)GridData::kExplosion)
		{
			break;
		}

		FVector spawnLocation = grid->GetWorldPositionFromGrid(xGridPosition, positionToCheck);

		grid->SetGridValueWithActorLocation(spawnLocation, (int32)GridData::kExplosion);

		AWTTestBombExplosion* spawnedExplosion =
			GetWorld()->SpawnActor<AWTTestBombExplosion>(m_BombExplosion, spawnLocation, FRotator(-80.0f), m_SpawnParameters);
		

		gridDisplacement++;
		positionToCheck--;
	}
}

void AWTTestBomb::CheckExplosionsExpansions() 
{
	UpExplosionExpansion();
	RightExplosionExpansion();
	DownExplosionExpansion();
	LeftExplosionExpansion();
}

void AWTTestBomb::SpawnCentralExplosion()
{
	int32 xGridPosition = 0;
	int32 yGridPosition = 0;
	auto grid = m_GameMode->m_MapManager;
	grid->GetGridValueWithLocation(GetActorLocation(), xGridPosition, yGridPosition);
	FVector spawnLocation = grid->GetWorldPositionFromGrid(xGridPosition, yGridPosition);

	grid->SetGridValueWithActorLocation(spawnLocation, (int32)GridData::kExplosion);

	AWTTestBombExplosion* spawnedExplosion =
		GetWorld()->SpawnActor<AWTTestBombExplosion>(m_BombExplosion, spawnLocation, FRotator(0.0f), m_SpawnParameters);
}
 
void AWTTestBomb::DestroyWallAtGridPosition(int32 xPosition, int32 yPosition)
{
  auto grid = m_GameMode->m_MapManager;

  AWTTestDestructibleWall* destructibleWall = Cast<AWTTestDestructibleWall>(grid->GetGridActor(xPosition, yPosition));
  check(IsValid(destructibleWall));
  destructibleWall->ProcessWallDestruction();
  grid->DestroyActorFromGrid(xPosition, yPosition);
  m_Owner->m_Score += 100;
}