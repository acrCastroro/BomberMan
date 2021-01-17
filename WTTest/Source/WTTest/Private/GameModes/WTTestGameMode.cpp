// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameModes/WTTestGameMode.h"
#include "Characters/WTTestCharacter.h"
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

int AWTTestGameMode::GetTimeRemainingToEndGame() const
{
	return (int)m_LevelTimer;
}

void AWTTestGameMode::AddBombsToPlayers()
{

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWTTestCharacter::StaticClass(), FoundActors);

	for (int i = 0; i < FoundActors.Num(); ++i)
	{
		AWTTestCharacter* player = Cast<AWTTestCharacter>(FoundActors[i]);
		check(IsValid(player));
		player->m_NumberOfAvailableBombs += 1;
	}

}
