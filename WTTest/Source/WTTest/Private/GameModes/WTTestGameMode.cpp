// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameModes/WTTestGameMode.h"
#include "Characters/WTTestCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

#include "Characters/WTTestCharacter.h"

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
  
  UGameplayStatics::GetAllActorsOfClass(world, AWTTestCharacter::StaticClass(), m_Players);
  
  UGameplayStatics::CreatePlayer(world, 0, true);
  UGameplayStatics::CreatePlayer(world, 1, true);
  
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
