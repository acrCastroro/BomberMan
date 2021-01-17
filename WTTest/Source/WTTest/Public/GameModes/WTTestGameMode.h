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
	float m_LevelTimer = 120.0;

	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = "Config|Level", meta = (DisplayName = "Map Manager"))
	bool m_bEndGame = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = "Config|Level", meta = (DisplayName = "Map Manager"))
	AWTTestMapManager* m_MapManager;

	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = "Config|Timers", meta = (DisplayName = "Time To Add Bombs"))
	float m_SecondsToAddBombs = 30.0f;

	FTimerHandle m_TimeToAddBombsToPlayersHandle;

	UFUNCTION(BlueprintCallable, Category = "GameProperties|Getters")
	int GetTimeRemainingToEndGame() const;

	UFUNCTION()
	void AddBombsToPlayers();

};



