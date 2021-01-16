// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/WTTestBombExplosion.h"

// Sets default values
AWTTestBombExplosion::AWTTestBombExplosion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	RootComponent = m_Mesh;

}

// Called when the game starts or when spawned
void AWTTestBombExplosion::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWTTestBombExplosion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

