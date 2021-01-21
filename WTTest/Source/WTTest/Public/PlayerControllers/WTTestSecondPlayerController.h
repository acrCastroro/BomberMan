// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



// --------- Engine Includes ------------
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
// --------- WTTest Includes ------------

#include "WTTestSecondPlayerController.generated.h"


class AWTTestCharacter;

UCLASS()
class WTTEST_API AWTTestSecondPlayerController : public APlayerController
{
	GENERATED_BODY()

	// --------------------------------------------------------
	// Constructors
	// --------------------------------------------------------

		AWTTestSecondPlayerController(const FObjectInitializer& ObjectInitializer);

	// --------------------------------------------------------
	// UE4 Functions
	// --------------------------------------------------------

protected:

	virtual void SetupInputComponent() override;

	virtual void OnPossess(APawn* InPawn) override;

	// --------------------------------------------------------
	// Input Functions
	// --------------------------------------------------------

protected:

	UFUNCTION()
		void Player2MoveForward(float value);

	UFUNCTION()
		void Player2MoveRight(float value);

	UFUNCTION()
		void Player2PlantBomb();

	// --------------------------------------------------------
	// Class Properties
	// --------------------------------------------------------

protected:

	UPROPERTY()
		AWTTestCharacter* m_Character;
	
};
