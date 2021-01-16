// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameModes/WTTestGameMode.h"
#include "Characters/WTTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

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
