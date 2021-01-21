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

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Mesh", meta = (DisplayName = "Mesh"))
	class UStaticMeshComponent* m_Mesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Collider", meta = (DisplayName = "Collider"))
	USphereComponent* m_Collider;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Config|Values", meta = (DisplayName = "Seconds To Expode"))
	float m_ExplosionTime = 1.5f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Config|Values|Resize")
   float m_ResizeTimeRatio = 0.33f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Config|Values|Resize")
   float m_ResizeSubstractionQuantity = 0.06f;

  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config|DamageType")
  TSubclassOf<class UDamageType> m_DamageType;

	FTimerHandle m_TimeToEndHandle;
  FTimerHandle m_TimeToResizeHanlde;

	// --------------------------------------------------------
	// Class Functions
	// --------------------------------------------------------

	UFUNCTION()
	void Overlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

  void Resize();

	void EndExplosion();
};
