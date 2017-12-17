// Copyright 2017 AngryGod of M.A.G. Studios

#pragma once

#include "GameFramework/Actor.h"
#include "Target.generated.h"

UCLASS()
class THEDAYSAFTER_API ATarget : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	ATarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
			
	// component static mesh
	UPROPERTY(EditAnyWhere, BluePrintReadWrite)
	UStaticMeshComponent* TargetMesh;

	// Called when target health is less than 0
	void DestroyTarget();

	// Value 0-100 target health
	float Health;

	// Applies Damage to target @paramDamage - Amount to damage target
	void DamageTarget(float Damage);
	
};
