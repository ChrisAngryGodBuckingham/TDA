// Copyright 2017 AngryGod of M.A.G. Studios

#pragma once

#include "Public/Core/TheDaysAfter.h"
#include "AI_Patrol.generated.h"

UCLASS()
class THEDAYSAFTER_API AAI_Patrol : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAI_Patrol();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = AI)
		class UBehaviorTree* BehaviorTree;

	UPROPERTY(VisibleAnywhere, Category = AI)
	class UPawnSensingComponent* PawnSensingComp;

private:

	UFUNCTION()
		void OnPlayerCaught(APawn* Pawn);

};
