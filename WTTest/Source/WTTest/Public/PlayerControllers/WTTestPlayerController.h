// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// --------- Engine Includes ------------
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
// --------- WTTest Includes ------------


#include "WTTestPlayerController.generated.h"

class AWTTestCharacter;

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

  virtual void BeginPlay() override;
	
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

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Config|Players", meta = (DisplayName = "Player1"))
	AWTTestCharacter* m_Character1;

  UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Config|Players", meta = (DisplayName = "Player2"))
  AWTTestCharacter* m_Character2;

  // --------------------------------------------------------
  // Class Functions
  // --------------------------------------------------------
public:

  UFUNCTION(BlueprintCallable)
  AWTTestCharacter* GetPlayer(int32 index);

  UFUNCTION(BlueprintImplementableEvent)
  void SetCharactersMaterials();

};
