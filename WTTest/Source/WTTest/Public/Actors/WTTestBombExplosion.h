// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "WTTestBombExplosion.generated.h"

UCLASS()
class WTTEST_API AWTTestBombExplosion : public AActor
{
	GENERATED_BODY()
	
public:	
	// --------------------------------------------------------
	// Constructors
	// --------------------------------------------------------

	AWTTestBombExplosion(const FObjectInitializer& ObjectInitializer);

	// --------------------------------------------------------
	// UE4 Functions
	// --------------------------------------------------------

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;
	// --------------------------------------------------------
	// Class Properties
	// --------------------------------------------------------

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Mesh")
	class UStaticMeshComponent* m_Mesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Collider")
	USphereComponent* m_Collider;

	// --------------------------------------------------------
	// Class Functions
	// --------------------------------------------------------

	UFUNCTION()
		void Overlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


};
