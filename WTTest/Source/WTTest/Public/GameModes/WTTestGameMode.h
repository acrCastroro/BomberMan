// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "Actors/WTTestMapManager.h"

#include "WTTestGameMode.generated.h"

UENUM(BlueprintType)
enum class GridData : uint8 
{
	kNothing = 0 UMETA(DisplayName = "NothingInGrid"),
	kDestructibleWall = 1  UMETA(DisplayName = "AddExplosionExpansion"),
	kIndesttructibleWall = 2     UMETA(DisplayName = "AddPlayerSpeed"),
	kPickups = 3					UMETA(DisplayName = "Pickups"),

	kExplosion UMETA(DisplayName = "MaxRange"),
};

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

	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = "Config|Level", meta = (DisplayName = "EndGame"))
	bool m_bEndGame = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = "Config|Level", meta = (DisplayName = "Level Timer"))
	float m_LevelTimer = 120.0;

	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = "Config|Timers", meta = (DisplayName = "Time To Add Bombs"))
	float m_SecondsToAddBombs = 30.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = "Config|GameModeValues", meta = (DisplayName = "Min number Pickups at start game"))
	int32 m_MinNumberOfPickupsAtStartGame = 2;

	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = "Config|GameModeValues", meta = (DisplayName = "Max number Pickups at start game"))
	int32 m_MaxNumberOfPickupsAtStartGame = 6;

	FTimerHandle m_TimeToAddBombsToPlayersHandle;

	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = "Config|Level", meta = (DisplayName = "Map Manager"))
	AWTTestMapManager* m_MapManager;

  UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = "Config|Level", meta = (DisplayName = "PlayersInGame"))
  TArray<AActor*> m_Players;

  UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = "Config|Level", meta = (DisplayName = "NumberOfPlayersInGame"))
  int32 m_NumberOfPlayersInGame = 2;

	UFUNCTION(BlueprintCallable, Category = "GameProperties|Getters")
	int32 GetTimeRemainingToEndGame() const;

	UFUNCTION()
	void AddBombsToPlayers();

};



