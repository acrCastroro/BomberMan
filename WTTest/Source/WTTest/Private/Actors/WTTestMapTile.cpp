// Fill out your copyright notice in the Description page of Project Settings.

// --------- WTTest Includes ------------
#include "Actors/WTTestMapTile.h"


AWTTestMapTile::AWTTestMapTile(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	m_CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMeshComponent"));

	RootComponent = m_CubeMesh;
}

void AWTTestMapTile::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AWTTestMapTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

