// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


// --------- Engine Includes ------------
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
// --------- WTTest Includes ------------

#include "WTTestBomb.generated.h"

class AWTTestGameMode;
class AWTTestBombExplosion;

UCLASS()
class WTTEST_API AWTTestBomb : public AActor
{
	GENERATED_BODY()

	// --------------------------------------------------------
	// Constructors
	// --------------------------------------------------------
	
public:	
	// Sets default values for this actor's properties
	AWTTestBomb(const FObjectInitializer& ObjectInitializer);

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
	// Class Proprerties
	// --------------------------------------------------------

public:

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Mesh")
	class UStaticMeshComponent* m_SphereMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Config|Values")
	float m_TimeToExplode = 3.0f;
  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Config|Values")
  float m_TimeToGrow = 1.0f;
  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Config|Values")
  float m_Damage = 110.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config|Explosion", meta = (DisplayName = "Bomb Explosion"))
	TSubclassOf<class AWTTestBombExplosion> m_BombExplosion;

	FTimerHandle m_TimeToExplodeHandle;
  FTimerHandle m_TimeToGrowHandle;
	   
	bool m_bActive = false;

	AWTTestGameMode* m_GameMode;

	FActorSpawnParameters m_SpawnParameters;

	// --------------------------------------------------------
	// Class Functions
	// --------------------------------------------------------

	UFUNCTION(BlueprintCallable, Category = "Actions")
	void Explode();

protected:

  void Grow();

	void UpExplosionExpansion();
	void RightExplosionExpansion();
	void DownExplosionExpansion();
	void LeftExplosionExpansion();

	void CheckExplosionsExpansions();

	void SpawnCentralExplosion();

  void DestroyWallAtGridPosition(int32 xPosition, int32 yPosition);

	// --------------------------------------------------------
	// Protected Properties
	// --------------------------------------------------------
	class AWTTestCharacter* m_Owner;

};
