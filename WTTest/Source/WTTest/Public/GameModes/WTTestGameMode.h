// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once


// --------- Engine Includes ------------
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
// --------- WTTest Includes ------------
#include "Actors/WTTestMapManager.h"


#include "WTTestGameMode.generated.h"

UENUM(BlueprintType)
enum class GridData : uint8 
{
	kNothing = 0 UMETA(DisplayName = "NothingInGrid"),
	kDestructibleWall = 1  UMETA(DisplayName = "DestructibleWall"),
	kIndesttructibleWall = 2     UMETA(DisplayName = "IndestructibleWall"),
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

  UPROPERTY(BlueprintReadwrite)
	bool m_bEndGame = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadwrite, Category = "Config|Level", meta = (DisplayName = "Level Timer"))
	float m_LevelTimer = 120.0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadwrite, Category = "Config|Timers", meta = (DisplayName = "Time To Add Bombs"))
	float m_SecondsToAddBombs = 30.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadwrite, Category = "Config|GameModeValues", meta = (DisplayName = "Min number Pickups at start game"))
	int32 m_MinNumberOfPickupsAtStartGame = 2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadwrite, Category = "Config|GameModeValues", meta = (DisplayName = "Max number Pickups at start game"))
	int32 m_MaxNumberOfPickupsAtStartGame = 6;

  int32 m_NumberOfPlayersInGame = 2;

	FTimerHandle m_TimeToAddBombsToPlayersHandle;

  UPROPERTY(EditDefaultsOnly, BlueprintReadwrite, Category = "Config|Level", meta = (DisplayName = "Map Manager"))
  TSubclassOf<AWTTestMapManager> m_MapManagerBP;

	UPROPERTY()
	AWTTestMapManager* m_MapManager;
  UPROPERTY()
  TArray<AActor*> m_Players;

  // --------------------------------------------------------
  // Class Functions
  // --------------------------------------------------------

	UFUNCTION(BlueprintCallable, Category = "GameProperties|Getters")
	int32 GetTimeRemainingToEndGame() const;

	UFUNCTION()
	void AddBombsToPlayers();

};



