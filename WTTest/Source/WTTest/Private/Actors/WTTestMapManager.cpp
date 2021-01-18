// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/WTTestMapManager.h"

#include "Actors/WTTestDestructibleWall.h"
#include "Actors/WTTestMapTile.h"
#include "Actors/WTTestPickups.h"
#include "GameModes/WTTestGameMode.h"

// Sets default values
AWTTestMapManager::AWTTestMapManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWTTestMapManager::BeginPlay()
{
	Super::BeginPlay();

	CreateGrid();
	SpawnGrid();

	AWTTestGameMode* gm = Cast<AWTTestGameMode>(GetWorld()->GetAuthGameMode());

	check(IsValid(gm));

	gm->m_MapManager = this;
	
}

// Called every frame
void AWTTestMapManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AWTTestMapManager::CreateGrid() 
{

	int32 maxRange = (int32)GridData::kExplosion - 1;

	for (int32 i = 0; i < m_kGridWidth; ++i)
	{
		for (int32 j = 0; j < m_kGridHeight; ++j)
		{
			m_Grid[i][j] = FMath::RandRange((int32)GridData::kNothing, maxRange);
		}
	}
}

void AWTTestMapManager::SpawnGrid()
{
	check(IsValid(m_Tile));

	FVector spawnLocation = GetActorLocation();
	FVector auxSpawnLocation = spawnLocation;
	FRotator spawnRotation = GetActorRotation();

	FActorSpawnParameters spawnParameters;
	spawnParameters.Instigator = GetInstigator();
	spawnParameters.Owner = this;

	int32 mapIndestructibleWallsSpawner = 0;
	int32 mapPickupsSpawner = 0;

	auxSpawnLocation.Z += 100.0f;

	for (int32 i = 0; i < m_kGridWidth; ++i)
	{		
		for (int32 j = 0; j < m_kGridHeight; ++j)
		{			
			AWTTestMapTile* spawnedTile = GetWorld()->SpawnActor<AWTTestMapTile>(m_Tile, FVector(auxSpawnLocation.X, auxSpawnLocation.Y, spawnLocation.Z), spawnRotation, spawnParameters);
			spawnedTile->SetOwner(this);

			if (m_Grid[i][j] == (int32)GridData::kDestructibleWall)
			{
				AWTTestDestructibleWall* destructibleWall =
					GetWorld()->SpawnActor<AWTTestDestructibleWall>(m_DestructibleWall, auxSpawnLocation, spawnRotation, spawnParameters);

				m_ActorsGrid[i][j] = destructibleWall;

			}
			else if (m_Grid[i][j] == (int32)GridData::kIndesttructibleWall) {

				if (mapIndestructibleWallsSpawner == 0)
				{
					spawnedTile =
						GetWorld()->SpawnActor<AWTTestMapTile>(m_Tile, auxSpawnLocation, spawnRotation, spawnParameters);
					m_ActorsGrid[i][j] = spawnedTile;
					
					mapIndestructibleWallsSpawner++;
				}
				else
				{
					m_Grid[i][j] = (int32)GridData::kNothing;
					mapIndestructibleWallsSpawner++;					
					if (mapIndestructibleWallsSpawner >= m_SpawnIndestructibleWallsRatio + 1) mapIndestructibleWallsSpawner = 0;					
				}
				
			}

			else if (m_Grid[i][j] == (int32)GridData::kPickups)
			{
				AWTTestPickups* PickUp =
					GetWorld()->SpawnActor<AWTTestPickups>(m_Pickups, auxSpawnLocation, spawnRotation, spawnParameters);

				m_ActorsGrid[i][j] = PickUp;

			}
			
			auxSpawnLocation.Y += 100;			
		}

		auxSpawnLocation.X -= 100;
		auxSpawnLocation.Y = spawnLocation.Y;
	}
}

int32 AWTTestMapManager::GetGridValue(int32 x, int32 y) 
{
	return m_Grid[x][y];
}

int32 AWTTestMapManager::GetGridValueWithLocation(FVector actorLocation, int32& xGridposition, int32& yGridPosition)
{	
	int32 x = FMath::Abs((actorLocation.X - m_XOffset) / 100.0f);
	int32 y = (actorLocation.Y + m_YOffset) / 100.0f;

	xGridposition = x;
	yGridPosition = y;
	
	return m_Grid[x][y];
}

AActor* AWTTestMapManager::GetGridActor(int32 x, int32 y)
{
	return m_ActorsGrid[x][y];
}

AActor* AWTTestMapManager::GetGridActorWithLocation(FVector actorLocation)
{
	int32 x = FMath::Abs((actorLocation.X - m_XOffset) / 100.0f);
	int32 y = (actorLocation.Y + m_YOffset) / 100.0f;

	return m_ActorsGrid[x][y];
}

FVector AWTTestMapManager::GetWorldPositionsFromGrid(int32 x, int32 y)
{
	FVector worldPosition;
	worldPosition.X = -(float)((x * 100));
	worldPosition.Y = (float)((y * 100));
	worldPosition.Z = 100.0f;
	return worldPosition;
}

void AWTTestMapManager::DestroyActorFromGrid(int32 x, int32 y)
{
	m_Grid[x][y] = 0;
	m_ActorsGrid[x][y]->Destroy();
}

void AWTTestMapManager::SetGridValueWithActorLocation(FVector actorLocation, int32 value)
{
	int32 x = FMath::Abs((actorLocation.X - m_XOffset) / 100.0f);
	int32 y = (actorLocation.Y + m_YOffset) / 100.0f;

	m_Grid[x][y] = value;
}

