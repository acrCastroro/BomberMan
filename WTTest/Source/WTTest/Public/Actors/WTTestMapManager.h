// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// --------------------------------------------------------
// Engine Includes
// --------------------------------------------------------
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// --------------------------------------------------------
// Own Includes
// --------------------------------------------------------

#include "WTTestMapManager.generated.h"

UCLASS()
class WTTEST_API AWTTestMapManager : public AActor
{
	GENERATED_BODY()
	
	// --------------------------------------------------------
	// Constructors
	// --------------------------------------------------------
public:	

	AWTTestMapManager(const FObjectInitializer& ObjectInitializer);

	// --------------------------------------------------------
	// UE4 Functions
	// --------------------------------------------------------

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	// --------------------------------------------------------
	// Class Functions
	// --------------------------------------------------------

	void CreateGrid();

	void SpawnGrid();

	UFUNCTION()
	void SpawnStartGamePickups();

	// --------------------------------------------------------
	// Class Properties
	// --------------------------------------------------------

public:

	static const int32 m_kGridWidth = 20;
	static const int32 m_kGridHeight = 20;

	int32 m_Grid[m_kGridWidth][m_kGridHeight] = {0};
	AActor* m_ActorsGrid[m_kGridWidth][m_kGridHeight] = {nullptr};

	float m_XOffset = 50.0f;
	float m_YOffset = 50.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config|Other_Actors")
	TSubclassOf<class AWTTestDestructibleWall> m_DestructibleWall;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config|Other_Actors")
	TSubclassOf<class AWTTestMapTile> m_Tile;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config|Other_Actors")
	TSubclassOf<class AWTTestPickups> m_Pickups;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Config|Design Values")
	int32 m_SpawnIndestructibleWallsRatio = 5;

	// --------------------------------------------------------
	// Class Functions
	// --------------------------------------------------------
	UFUNCTION(BlueprintCallable)
	int32 GetGridValue(int32 x, int32 y);
	UFUNCTION(BlueprintCallable)
	int32 GetGridValueWithLocation(FVector actorLocation, int32& xGridposition, int32& yGridPosition);

	UFUNCTION(BlueprintCallable)
	AActor* GetGridActor(int32 x, int32 y);
	UFUNCTION(BlueprintCallable)
	AActor* GetGridActorWithLocation(FVector actorLocation);

	UFUNCTION(BlueprintCallable)
	FVector GetWorldPositionFromGrid(int32 x, int32 y);

	UFUNCTION(BlueprintCallable)
	void DestroyActorFromGrid(int32 x, int32 y);

	UFUNCTION(BlueprintCallable)
	void SetGridValueWithActorLocation(FVector actorLocation, int32 value);

	UFUNCTION(BlueprintCallable)
	void SetGridValue(int32 x, int32 y, int32 value);



};
