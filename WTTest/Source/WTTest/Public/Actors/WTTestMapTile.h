// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WTTestMapTile.generated.h"

UCLASS()
class WTTEST_API AWTTestMapTile : public AActor
{
	GENERATED_BODY()

	// --------------------------------------------------------
	// Constructors
	// --------------------------------------------------------
	
public:	

	AWTTestMapTile(const FObjectInitializer& ObjectInitializer);

	// --------------------------------------------------------
	// UE4 Functions
	// --------------------------------------------------------

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	// --------------------------------------------------------
	// Class Properties
	// --------------------------------------------------------

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Config|Mesh")
	class UStaticMeshComponent* m_CubeMesh;

};
