// Copyright 2017 AngryGod of M.A.G. Studios

#pragma once

#include "Public/Core/TheDaysAfter.h"
#include "TheDaysAfter_AI_Base.generated.h"

UCLASS()
class THEDAYSAFTER_API ATheDaysAfter_AI_Base : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATheDaysAfter_AI_Base();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI_Variables)
	bool bIsWalking;
	bool bIsTalking;
	float WalkSpeed;
	float WalkRadius;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
