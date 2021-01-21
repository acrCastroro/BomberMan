// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


// --------- Engine Includes ------------
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
// --------- WTTest Includes ------------


#include "WTTestEndGameUserWidget.generated.h"

UCLASS()
class WTTEST_API UWTTestEndGameUserWidget : public UUserWidget
{
	GENERATED_BODY()

	// ------------------------------------------------------------------------                       
	// Constructors
	// ------------------------------------------------------------------------
public:

	UWTTestEndGameUserWidget(const FObjectInitializer& ObjectInitializer);
	
};
