// Copyright 2017 AngryGod of M.A.G. Studios

#include "Target.h"


// Sets default values
ATarget::ATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Health = 100.f;

	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pickup Mesh"));
	RootComponent = TargetMesh;

}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATarget::DamageTarget(float Damage)
{
	Health -= Damage;
	if (Health <= 0.f)
	{
		DestroyTarget();
	}
}

// Can add extra functionality like effects here
void ATarget::DestroyTarget()
{
	Destroy();
}
