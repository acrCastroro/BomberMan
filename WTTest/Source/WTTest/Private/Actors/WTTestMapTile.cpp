// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/WTTestMapTile.h"

// Sets default values
AWTTestMapTile::AWTTestMapTile(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMeshComponent"));
	m_Spawner = CreateDefaultSubobject<USceneComponent>(TEXT("Spawner"));

	RootComponent = m_CubeMesh;
	m_Spawner->AttachTo(m_CubeMesh);

}

// Called when the game starts or when spawned
void AWTTestMapTile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWTTestMapTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

