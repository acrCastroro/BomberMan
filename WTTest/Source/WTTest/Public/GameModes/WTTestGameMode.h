// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WTTestGameMode.generated.h"

UCLASS(minimalapi)
class AWTTestGameMode : public AGameModeBase
{  
	GENERATED_BODY()

	// --------------------------------------------------------
	// Constructors
	// --------------------------------------------------------

public:
	AWTTestGameMode(const FObjectInitializer& ObjectInitializer);

	// --------------------------------------------------------
	// UE4 Functions
	// --------------------------------------------------------

	virtual void BeginPlay();

	virtual void Tick(float DeltaSeconds) override;

	// --------------------------------------------------------
	// Class Properties
	// --------------------------------------------------------

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = "Config|Level", meta = (DisplayName = "Level Timer"))
	float m_LevelTimer = 120.0f;

};



