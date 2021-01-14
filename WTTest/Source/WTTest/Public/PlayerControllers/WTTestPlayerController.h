// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "WTTestPlayerController.generated.h"

class AWTTestCharacter;

/**
 * 
 */
UCLASS()
class WTTEST_API AWTTestPlayerController : public APlayerController
{
	GENERATED_BODY()

	// --------------------------------------------------------
	// Constructors
	// --------------------------------------------------------

	AWTTestPlayerController(const FObjectInitializer& ObjectInitializer);

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
	void Player1MoveForward(float value);

	UFUNCTION()
	void Player1MoveRight(float value);

	UFUNCTION()
	void Player1PlantBomb();

	// --------------------------------------------------------
	// Class Properties
	// --------------------------------------------------------

protected:

	UPROPERTY()
	AWTTestCharacter* m_Character;
	
};