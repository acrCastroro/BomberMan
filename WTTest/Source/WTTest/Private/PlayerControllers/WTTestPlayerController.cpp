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

	InputComponent->BindAxis("P1MoveForward", this, &AWTTestPlayerController::PlayerMoveForward);
	InputComponent->BindAxis("P1MoveRight", this, &AWTTestPlayerController::PlayerMoveRight);

	InputComponent->BindAction("P1PlantBomb", IE_Pressed, this, &AWTTestPlayerController::PlayerPlantBomb);

}

void AWTTestPlayerController::OnPossess(APawn* InPawn) 
{
	Super::OnPossess(InPawn);

	m_Character = Cast<AWTTestCharacter>(InPawn);
}

// --------------------------------------------------------
// Input Functions
// --------------------------------------------------------

void AWTTestPlayerController::PlayerMoveForward(float value) 
{
	if (IsValid(m_Character) && FMath::IsNearlyZero(value) == false)
	{
		m_Character->MoveForward(value);
	}
}

void AWTTestPlayerController::PlayerMoveRight(float value) 
{
	if (IsValid(m_Character) && FMath::IsNearlyZero(value) == false)
	{
		m_Character->MoveRight(value);
	}
}

void AWTTestPlayerController::PlayerPlantBomb() 
{
	if (IsValid(m_Character)) 
	{
		m_Character->PlantBomb();
	}
}