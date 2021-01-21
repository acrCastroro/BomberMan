// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once


// --------- Engine Includes ------------
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
// --------- WTTest Includes ------------


#include "WTTestCharacter.generated.h"


UCLASS(config=Game)
class AWTTestCharacter : public ACharacter
{
	GENERATED_BODY()

public:
  // --------------------------------------------------------
  // Constructors
  // --------------------------------------------------------
	AWTTestCharacter();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

  // --------------------------------------------------------
  // UE4 Functions
  // --------------------------------------------------------
public:

  virtual void BeginPlay() override;

  virtual float TakeDamage(float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

  // --------------------------------------------------------
  // Class Properties
  // --------------------------------------------------------

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config|Bombs", meta = (DisplayName = "Bombs"))
	TSubclassOf<class AWTTestBomb> m_Bombs;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Config|Values")
	int32 m_NumberOfAvailableBombs = 1;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Config|Values")
	int32 m_MaxNumberOfAvailableBombs = 5;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Config|Values")
	int32 m_CurrentExplosionTileDistance = 2;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Config|Values")
	int32 m_MaxExplosionTileDistance = 8;

  UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Config|Values")
  float m_MaxHealth = 100.0f;

  UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Config|Values")
  float m_CurrentHealth = m_MaxHealth;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Config|Score")
	int32 m_Score = 0;

  UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Config|State")
  bool m_Alive = true;

  // --------------------------------------------------------
  // Class Functions
  // --------------------------------------------------------

  void MoveForward(float Value);

  void MoveRight(float Value);

  void PlantBomb();


};

