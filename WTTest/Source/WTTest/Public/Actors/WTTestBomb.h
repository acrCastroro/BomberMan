// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Config|Values")
	float m_TimeToExplode = 3.0f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Config|Values")
	int m_MaxExplosionTileDistance = 3;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config|Explosion", meta = (DisplayName = "Bomb Explosion"))
	TSubclassOf<class AWTTestBombExplosion> m_BombExplosion;

	FTimerHandle m_TimeToExplodeHandle;
	   
	bool m_bActive = false;

	AWTTestGameMode* m_GameMode;

	FActorSpawnParameters m_SpawnParameters;
	// --------------------------------------------------------
	// Class Functions
	// --------------------------------------------------------

	UFUNCTION(BlueprintCallable, Category = "Actions")
	void Explode();

protected:


	void UpExplosionExpansion();
	void RightExplosionExpansion();
	void DownExplosionExpansion();
	void LeftExplosionExpansion();

	void CheckExplosionsExpansions();

	void SpawnCentralExplosion();

	// --------------------------------------------------------
	// Protected Properties
	// --------------------------------------------------------
	class AWTTestCharacter* m_Owner;

};
