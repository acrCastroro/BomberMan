// Fill out your copyright notice in the Description page of Project Settings.



// --------- WTTest Includes ------------
#include "PlayerControllers/WTTestPlayerController.h"
#include "Characters/WTTestCharacter.h"
// --------- Engine Includes ------------
#include "Kismet/GameplayStatics.h"

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

void AWTTestPlayerController::BeginPlay()
{
  Super::BeginPlay();

  m_Character1 = Cast<AWTTestCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

  m_Character2 = Cast<AWTTestCharacter>(UGameplayStatics::GetPlayerCharacter(this, 1));

  SetCharactersMaterials();
}

void AWTTestPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

  //Player1 Input
	InputComponent->BindAxis("P1MoveForward", this, &AWTTestPlayerController::Player1MoveForward);
	InputComponent->BindAxis("P1MoveRight", this, &AWTTestPlayerController::Player1MoveRight);
	InputComponent->BindAction("P1PlantBomb", IE_Pressed, this, &AWTTestPlayerController::Player1PlantBomb);
  
  //Player2 Input
  InputComponent->BindAxis("P2MoveForward", this, &AWTTestPlayerController::Player2MoveForward);
  InputComponent->BindAxis("P2MoveRight", this, &AWTTestPlayerController::Player2MoveRight);
  InputComponent->BindAction("P2PlantBomb", IE_Pressed, this, &AWTTestPlayerController::Player2PlantBomb);

}

void AWTTestPlayerController::OnPossess(APawn* InPawn)
{
  Super::OnPossess(InPawn);
}

// --------------------------------------------------------
// Input Functions
// --------------------------------------------------------

void AWTTestPlayerController::Player1MoveForward(float value) 
{
	if (IsValid(m_Character1) && FMath::IsNearlyZero(value) == false)
	{
		m_Character1->MoveForward(value);
	}
}

void AWTTestPlayerController::Player1MoveRight(float value) 
{
	if (IsValid(m_Character1) && FMath::IsNearlyZero(value) == false)
	{
		m_Character1->MoveRight(value);
	}
}

void AWTTestPlayerController::Player1PlantBomb() 
{
	if (IsValid(m_Character1)) 
	{
		m_Character1->PlantBomb();
	}
}

void AWTTestPlayerController::Player2MoveForward(float value)
{
  if (IsValid(m_Character2) && FMath::IsNearlyZero(value) == false)
  {
    m_Character2->MoveForward(value);
  }
}

void AWTTestPlayerController::Player2MoveRight(float value)
{
  if (IsValid(m_Character2) && FMath::IsNearlyZero(value) == false)
  {
    m_Character2->MoveRight(value);
  }
}

void AWTTestPlayerController::Player2PlantBomb()
{
  if (IsValid(m_Character2))
  {
    m_Character2->PlantBomb();
  }
}

AWTTestCharacter* AWTTestPlayerController::GetPlayer(int32 index)
{
  if (index == 1)
  {
    return m_Character1;
  }
  return m_Character2;
}