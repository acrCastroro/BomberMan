// Copyright Epic Games, Inc. All Rights Reserved.



// --------- WTTest Includes ------------
#include "Characters/WTTestCharacter.h"
#include "Actors/WTTestBomb.h"
#include "GameModes/WTTestGameMode.h"
#include "GameInstance/WTTestGameInstance.h"
#include "PlayerControllers/WTTestPlayerController.h"
// --------- Engine Includes ------------
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"


AWTTestCharacter::AWTTestCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;
}

void AWTTestCharacter::BeginPlay()
{
  Super::BeginPlay();
}

float AWTTestCharacter::TakeDamage(float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
  const float kBaseTakeDamage = Super::TakeDamage(DamageTaken, DamageEvent, EventInstigator, DamageCauser);

  m_CurrentHealth -= kBaseTakeDamage;

  if (m_CurrentHealth <= 0.0f)
  {
    GetMesh()->SetVisibility(false);
    m_Alive = false;
    AWTTestGameMode* gm = Cast<AWTTestGameMode>(GetWorld()->GetAuthGameMode());
    gm->m_bEndGame = true;

    auto gI = Cast<UWTTestGameInstance>(GetWorld()->GetGameInstance());
    auto playerController = Cast <AWTTestPlayerController>(this->GetController());
    
    if (this == playerController->GetPlayer(1))
    {
      gI->m_Player1Wins++;
    }
    else
    {
      gI->m_Player2Wins++;
    }
  }

  return DamageTaken;
}

void AWTTestCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AWTTestCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{

		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void AWTTestCharacter::PlantBomb() {

	 AWTTestGameMode* gm =  Cast<AWTTestGameMode>(GetWorld()->GetAuthGameMode());

	 if (m_NumberOfAvailableBombs > 0)
	 {

		FVector spawnLocation = GetActorLocation();
		FRotator spawnRotation = GetActorRotation();
		spawnLocation.Z -= 50.0f;

		FActorSpawnParameters spawnParameters;
		spawnParameters.Instigator = GetInstigator();
		spawnParameters.Owner = this;

		check(IsValid(m_Bombs));
		AWTTestBomb* spawnedBomb = GetWorld()->SpawnActor<AWTTestBomb>(m_Bombs, spawnLocation, spawnRotation, spawnParameters);

		m_NumberOfAvailableBombs--;

	 }
}
