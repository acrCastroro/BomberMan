// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


// --------- Engine Includes ------------
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
// --------- WTTest Includes ------------


#include "WTTestPlayersInfoUserWidget.generated.h"

UCLASS()
class WTTEST_API UWTTestPlayersInfoUserWidget : public UUserWidget
{
	GENERATED_BODY()
	// ------------------------------------------------------------------------                       
	// Constructors
	// ------------------------------------------------------------------------
public:

	UWTTestPlayersInfoUserWidget(const FObjectInitializer& ObjectInitializer);
};
