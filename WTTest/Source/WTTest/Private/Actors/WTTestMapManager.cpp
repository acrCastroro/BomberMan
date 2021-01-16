// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/WTTestMapManager.h"

#include "Actors/WTTestDestructibleWall.h"
#include "Actors/WTTestMapTile.h"

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
	
}

// Called every frame
void AWTTestMapManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AWTTestMapManager::CreateGrid() 
{
	for (int32 i = 0; i < m_kGridWidth; ++i)
	{
		for (int32 j = 0; j < m_kGridHeight; ++j)
		{
			m_Grid[i][j] = FMath::RandRange(0, 2);
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

	for (int32 i = 0; i < m_kGridWidth; ++i)
	{		
		for (int32 j = 0; j < m_kGridHeight; ++j)
		{			
			AWTTestMapTile* spawnedTile = GetWorld()->SpawnActor<AWTTestMapTile>(m_Tile, auxSpawnLocation, spawnRotation, spawnParameters);
			spawnedTile->SetOwner(this);

			if (m_Grid[i][j] == 1)
			{
				AWTTestDestructibleWall* destructibleWall =
					GetWorld()->SpawnActor<AWTTestDestructibleWall>(m_DestructibleWall, FVector(auxSpawnLocation.X, auxSpawnLocation.Y, auxSpawnLocation.Z + 100), spawnRotation, spawnParameters);
				
				m_ActorsGrid[i][j] = destructibleWall;

			}
			else if (m_Grid[i][j] == 2) {
				 spawnedTile = GetWorld()->SpawnActor<AWTTestMapTile>(m_Tile, FVector(auxSpawnLocation.X, auxSpawnLocation.Y, auxSpawnLocation.Z + 100), spawnRotation, spawnParameters);
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

