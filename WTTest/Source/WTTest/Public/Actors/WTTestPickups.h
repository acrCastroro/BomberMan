// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WTTestPickups.generated.h"


UENUM(BlueprintType)
enum class PickupTypes : uint8 {
	kAddBomb = 0 UMETA(DisplayName = "AddBomb"),
	kAddExplosionExpansion = 1  UMETA(DisplayName = "AddExplosionExpansion"),
	kAddPlayerSpeed = 2     UMETA(DisplayName = "AddPlayerSpeed"),
	
	kMax UMETA(DisplayName = "MaxRange"),
};

UCLASS()
class WTTEST_API AWTTestPickups : public AActor
{
	GENERATED_BODY()
	
	// --------------------------------------------------------
	// Constructors
	// --------------------------------------------------------

public:
	// Sets default values for this actor's properties
	AWTTestPickups(const FObjectInitializer& ObjectInitializer);

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
	UFUNCTION(BlueprintCallable)
	PickupTypes GetPickupType();

	void SetPowerup();

	// --------------------------------------------------------
	// Class Properties
	// --------------------------------------------------------

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Mesh")
	class UStaticMeshComponent* m_Mesh;

	

protected:
	PickupTypes m_PickupType;	

	//PickupTypes m_PickUpTipes;
	

};
