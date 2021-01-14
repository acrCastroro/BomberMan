// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/WTTestDestructibleWall.h"

// Sets default values
AWTTestDestructibleWall::AWTTestDestructibleWall(const FObjectInitializer& ObjectInitializer): 
	Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMeshComponent"));

	RootComponent = m_CubeMesh;
}

// Called when the game starts or when spawned
void AWTTestDestructibleWall::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AWTTestDestructibleWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

