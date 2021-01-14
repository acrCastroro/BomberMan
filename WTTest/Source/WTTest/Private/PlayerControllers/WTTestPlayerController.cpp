// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllers/WTTestPlayerController.h"

#include "Characters/WTTestCharacter.h"

// --------------------------------------------------------
// Constructors
// --------------------------------------------------------


AWTTestPlayerController::AWTTestPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

// --------------------------------------------------------
// UE4 Functions
// --------------------------------------------------------

void AWTTestPlayerController::SetupInputComponent()
{

	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &AWTTestPlayerController::Player1MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AWTTestPlayerController::Player1MoveRight);

	InputComponent->BindAction("P1PlantBomb", IE_Pressed, this, &AWTTestPlayerController::Player1PlantBomb);

}

void AWTTestPlayerController::OnPossess(APawn* InPawn) 
{
	Super::OnPossess(InPawn);

	m_Character = Cast<AWTTestCharacter>(InPawn);
}

// --------------------------------------------------------
// Input Functions
// --------------------------------------------------------

void AWTTestPlayerController::Player1MoveForward(float value) 
{
	if (IsValid(m_Character) && FMath::IsNearlyZero(value) == false)
	{
		m_Character->MoveForward(value);
	}
}

void AWTTestPlayerController::Player1MoveRight(float value) 
{
	if (IsValid(m_Character) && FMath::IsNearlyZero(value) == false)
	{
		m_Character->MoveRight(value);
	}
}

void AWTTestPlayerController::Player1PlantBomb() 
{
	if (IsValid(m_Character)) 
	{
		m_Character->PlantBomb();
	}
}