// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


// --------- Engine Includes ------------
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
// --------- WTTest Includes ------------

#include "WTTestHUD.generated.h"


UCLASS()
class WTTEST_API AWTTestHUD : public AHUD
{
  GENERATED_BODY()

  // --------------------------------------------------------
  // Constructors
  // --------------------------------------------------------

    AWTTestHUD(const FObjectInitializer& ObjectInitializer);	
};
