// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "Actors/WTTestMapManager.h"

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config|Actors", meta = (DisplayName = "Map Manager"))
	TSubclassOf<AWTTestMapManager> m_MapManagerBP;

	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = "Config|Level", meta = (DisplayName = "Level Timer"))
	AWTTestMapManager* m_MapManager;

};



