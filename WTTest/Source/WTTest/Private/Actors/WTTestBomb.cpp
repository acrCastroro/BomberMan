// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/WTTestBomb.h"
#include "Characters/WTTestCharacter.h"
#include "GameModes/WTTestGameMode.h"

// Sets default values
AWTTestBomb::AWTTestBomb(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	RootComponent = m_SphereMesh;
}

// Called when the game starts or when spawned
void AWTTestBomb::BeginPlay()
{
	Super::BeginPlay();

	UWorld* world = GetWorld();
	m_GameMode = Cast<AWTTestGameMode>(GetWorld()->GetAuthGameMode());
	
	if (IsValid(world)) 
	{
		world->GetTimerManager().SetTimer(m_TimeToExplodeHandle, this, &AWTTestBomb::Explode, m_TimeToExplode, false);
	}
	
}

// Called every frame
void AWTTestBomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWTTestBomb::Explode() 
{
	AWTTestCharacter* owner = Cast<AWTTestCharacter>(GetOwner());

	check(IsValid(owner));

	owner->m_NumberOfAvailableBombs++;

	CheckExplosionsExpansions();

	Destroy();
}

void AWTTestBomb::UpExplosionExpansion()
{

	int32 xGridPosition = 0;
	int32 yGridPosition = 0;
	auto grid = m_GameMode->m_MapManager;
	grid->GetGridValueWithLocation(GetActorLocation(), xGridPosition, yGridPosition);

	int32 gridDisplacement = 0;
	int32 positionToCheck = xGridPosition - 1;

	while (gridDisplacement < m_MaxExplosionTileDistance)
	{

		if (positionToCheck < 0 || positionToCheck > grid->m_kGridHeight) break;

		int32 aux = grid->GetGridValue(positionToCheck, yGridPosition);

		if (aux == 1) {
			grid->DestroyActorFromGrid(positionToCheck, yGridPosition);
			break;
		}
		else if (aux == 2)
		{
			break;
		}

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

	while (gridDisplacement < m_MaxExplosionTileDistance)
	{

		if (positionToCheck < 0 || positionToCheck > grid->m_kGridWidth) break;

		int32 aux = grid->GetGridValue(xGridPosition, positionToCheck);

		if (aux == 1) {
			grid->DestroyActorFromGrid(xGridPosition, positionToCheck);
			break;
		}
		else if (aux == 2)
		{
			break;
		}

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

	while (gridDisplacement < m_MaxExplosionTileDistance)
	{

		if (positionToCheck < 0 || positionToCheck > grid->m_kGridHeight) break;

		int32 aux = grid->GetGridValue(positionToCheck, yGridPosition);

		if (aux == 1) {
			grid->DestroyActorFromGrid(positionToCheck, yGridPosition);
			break;
		}
		else if (aux == 2)
		{
			break;
		}

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

	while (gridDisplacement < m_MaxExplosionTileDistance)
	{

		if (positionToCheck < 0 || positionToCheck > grid->m_kGridWidth) break;

		int32 aux = grid->GetGridValue(xGridPosition, positionToCheck);

		if (aux == 1) {
			grid->DestroyActorFromGrid(xGridPosition, positionToCheck);
			break;
		}
		else if (aux == 2)
		{
			break;
		}

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

