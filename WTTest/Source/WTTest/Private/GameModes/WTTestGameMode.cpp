// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameModes/WTTestGameMode.h"
#include "Characters/WTTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWTTestGameMode::AWTTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
