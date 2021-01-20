// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/WTTestBombExplosion.h"
#include "Characters/WTTestCharacter.h"
#include "Actors/WTTestBomb.h"
#include "GameModes/WTTestGameMode.h"

#include "Kismet/GameplayStatics.h"


// Sets default values
AWTTestBombExplosion::AWTTestBombExplosion(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	m_Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));

	RootComponent = m_Mesh;

	m_Collider->SetupAttachment(RootComponent);
	m_Collider->SetGenerateOverlapEvents(true);

	m_Collider->SetWorldScale3D(FVector(100.0f));

  m_DamageType = UDamageType::StaticClass();

}

// Called when the game starts or when spawned
void AWTTestBombExplosion::BeginPlay()
{
	Super::BeginPlay();

	m_Collider->OnComponentBeginOverlap.AddDynamic(this, &AWTTestBombExplosion::Overlap);

	UWorld* world = GetWorld();

	if (IsValid(world))
	{
		world->GetTimerManager().SetTimer(m_TimeToEndHandle, this, &AWTTestBombExplosion::EndExplosion, m_ExplosionTime, false);
	}
	
}

// Called every frame
void AWTTestBombExplosion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWTTestBombExplosion::Overlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
  GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, OtherActor->GetName());
	if ((OtherActor != nullptr) && (OtherActor != this))
	{

		AWTTestBomb* bomb = Cast<AWTTestBomb>(OtherActor);
		if (IsValid(bomb))
		{
			if(bomb->m_bActive == false) 
			{
			GetWorldTimerManager().ClearTimer(bomb->m_TimeToExplodeHandle);
			bomb->Explode();
			}
		}

    AWTTestCharacter* character = Cast<AWTTestCharacter>(OtherActor);
    if (IsValid(character))
    {     
        UGameplayStatics::ApplyDamage(character, 110.0f, GetInstigatorController(), this, m_DamageType);
    }

	}
}


void AWTTestBombExplosion::EndExplosion() 
{
	AWTTestGameMode* gameMode = Cast<AWTTestGameMode>(GetWorld()->GetAuthGameMode());

	if (IsValid(gameMode))
	{
		gameMode->m_MapManager->SetGridValueWithActorLocation(GetActorLocation(), 0);
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "Cambio Valor");
	}

	Destroy();

}