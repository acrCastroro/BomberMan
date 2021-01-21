// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "WTTestDestructibleWall.generated.h"

UCLASS()
class WTTEST_API AWTTestDestructibleWall : public AActor
{
	GENERATED_BODY()
	
	// --------------------------------------------------------
	// Constructors
	// --------------------------------------------------------
	AWTTestDestructibleWall(const FObjectInitializer& ObjectInitializer);

	// --------------------------------------------------------
	// UE4 Functions
	// --------------------------------------------------------
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

  virtual void Destroyed() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// --------------------------------------------------------
	// Class Properties
	// --------------------------------------------------------

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Collider")
	class UStaticMeshComponent* m_CubeMesh;

  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Actors|Pickups")
  TSubclassOf<class AWTTestPickups> m_Pickup;

  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Actors|Pickups")
   int32 m_PickUpSpawningRatio = 6;

};
