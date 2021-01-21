// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


// --------- Engine Includes ------------
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
// --------- WTTest Includes ------------


#include "WTTestGameModeUserWidget.generated.h"

UCLASS()
class WTTEST_API UWTTestGameModeUserWidget : public UUserWidget
{
	GENERATED_BODY()
	// ------------------------------------------------------------------------                       
	// Constructors
	// ------------------------------------------------------------------------
public:

	UWTTestGameModeUserWidget(const FObjectInitializer& ObjectInitializer);
	
};
