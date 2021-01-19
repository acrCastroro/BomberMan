// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "WTTestGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class WTTEST_API UWTTestGameInstance : public UGameInstance
{
	GENERATED_BODY()

	// --------------------------------------------------------
	// Constructors
	// --------------------------------------------------------

public:
    UWTTestGameInstance(const FObjectInitializer& ObjectInitializer);

	// --------------------------------------------------------
	// Class Properties
	// --------------------------------------------------------

    UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Game|Players")
    int32 m_Player1Score = 0;

    UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Game|Players")
    int32 m_Player2Score = 0;

};
