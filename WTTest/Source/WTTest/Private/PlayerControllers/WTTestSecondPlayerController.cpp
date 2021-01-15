// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllers/WTTestSecondPlayerController.h"

#include "Characters/WTTestCharacter.h"

// --------------------------------------------------------
// Constructors
// --------------------------------------------------------


AWTTestSecondPlayerController::AWTTestSecondPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

// --------------------------------------------------------
// UE4 Functions
// --------------------------------------------------------

void AWTTestSecondPlayerController::SetupInputComponent()
{

	Super::SetupInputComponent();

	InputComponent->BindAxis("P2MoveForward", this, &AWTTestSecondPlayerController::Player2MoveForward);
	InputComponent->BindAxis("P2MoveRight", this, &AWTTestSecondPlayerController::Player2MoveRight);

	InputComponent->BindAction("P2PlantBomb", IE_Pressed, this, &AWTTestSecondPlayerController::Player2PlantBomb);

}

void AWTTestSecondPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	m_Character = Cast<AWTTestCharacter>(InPawn);
}

// --------------------------------------------------------
// Input Functions
// --------------------------------------------------------

void AWTTestSecondPlayerController::Player2MoveForward(float value)
{
	if (IsValid(m_Character) && FMath::IsNearlyZero(value) == false)
	{
		m_Character->MoveForward(value);
	}
}

void AWTTestSecondPlayerController::Player2MoveRight(float value)
{
	if (IsValid(m_Character) && FMath::IsNearlyZero(value) == false)
	{
		m_Character->MoveRight(value);
	}
}

void AWTTestSecondPlayerController::Player2PlantBomb()
{
	if (IsValid(m_Character))
	{
		m_Character->PlantBomb();
	}
}