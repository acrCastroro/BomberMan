// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/WTTestBomb.h"
#include "Characters/WTTestCharacter.h"

// Sets default values
AWTTestBomb::AWTTestBomb(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	RootComponent = m_SphereMesh;
}

// Called when the game starts or when spawned
void AWTTestBomb::BeginPlay()
{
	Super::BeginPlay();

	UWorld* world = GetWorld();
	
	if (IsValid(world)) 
	{
		world->GetTimerManager().SetTimer(m_TimeToExplodeHandle, this, &AWTTestBomb::Explode, m_TimeToExplode, false);
	}
	
}

// Called every frame
void AWTTestBomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWTTestBomb::Explode() 
{
	AWTTestCharacter* owner = Cast<AWTTestCharacter>(GetOwner());

	check(IsValid(owner));

	owner->m_NumberOfAvailableBombs++;

	Destroy();

}

