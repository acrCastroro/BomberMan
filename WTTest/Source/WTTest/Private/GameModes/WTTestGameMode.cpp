// Copyright Epic Games, Inc. All Rights Reserved.

// --------- WTTest Includes ------------
#include "GameModes/WTTestGameMode.h"
#include "Characters/WTTestCharacter.h"
// --------- Engine Includes ------------
#include "UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"



AWTTestGameMode::AWTTestGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

}

void AWTTestGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(m_TimeToAddBombsToPlayersHandle, this, &AWTTestGameMode::AddBombsToPlayers, m_SecondsToAddBombs, true);
  
  UWorld* world = GetWorld();

  check(IsValid(world));
  
  UGameplayStatics::CreatePlayer(world, 0, true);
  UGameplayStatics::CreatePlayer(world, 1, true);

  UGameplayStatics::GetAllActorsOfClass(world, AWTTestCharacter::StaticClass(), m_Players);
 
  FActorSpawnParameters spawnParameters;
  spawnParameters.Instigator = GetInstigator();
  spawnParameters.Owner = this;
  check(IsValid(m_MapManagerBP));
  m_MapManager = GetWorld()->SpawnActor<AWTTestMapManager>(m_MapManagerBP, FVector(0.0f), FRotator(0.0f), spawnParameters);
  check(IsValid(m_MapManager));
}

void AWTTestGameMode::Tick(float DeltaSeconds) 
{
	Super::Tick(DeltaSeconds);

	m_LevelTimer -= DeltaSeconds;

	if (m_LevelTimer <= 0.0f)
	{
		m_LevelTimer = 0.0f;
		m_bEndGame = true;	
	}
}

int32 AWTTestGameMode::GetTimeRemainingToEndGame() const
{
	return (int32)m_LevelTimer;
}

void AWTTestGameMode::AddBombsToPlayers()
{  
	for (int i = 0; i < m_Players.Num(); ++i)
	{
		AWTTestCharacter* player = Cast<AWTTestCharacter>(m_Players[i]);
		check(IsValid(player));
		player->m_NumberOfAvailableBombs += 1;
	}
}
