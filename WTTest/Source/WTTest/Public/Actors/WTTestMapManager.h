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
	// Sets default values for this actor's properties
	AWTTestMapManager(const FObjectInitializer& ObjectInitializer);

	// --------------------------------------------------------
	// UE4 Functions
	// --------------------------------------------------------

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// --------------------------------------------------------
	// Class Functions
	// --------------------------------------------------------

	void CreateGrid();

	void SpawnGrid();

	void SpawnGridObjects();

	// --------------------------------------------------------
	// Class Properties
	// --------------------------------------------------------

public:

	static const int32 m_kGridWidth = 20;
	static const int32 m_kGridHeight = 20;

	int32 m_Grid[m_kGridWidth][m_kGridHeight];

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config|Other_Actors")
	TSubclassOf<class AWTTestDestructibleWall> m_DestructibleWall;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config|Other_Actors")
	TSubclassOf<class AWTTestMapTile> m_Tile;

};
