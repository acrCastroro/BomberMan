// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WTTestCharacter.generated.h"


UCLASS(config=Game)
class AWTTestCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AWTTestCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

public:

  virtual void BeginPlay() override;

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	void PlantBomb();

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
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Config|Score")
	int32 m_Score = 0;

protected:

};

