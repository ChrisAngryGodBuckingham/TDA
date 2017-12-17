// Copyright 2017 AngryGod of M.A.G. Studios

#pragma once

#include "Public/Core/TheDaysAfter.h"

#include "AI_Patrol_Controller.generated.h"

/**
 * 
 */
UCLASS()
class THEDAYSAFTER_API AAI_Patrol_Controller : public AAIController
{
	GENERATED_BODY()

		//behavior tree component
		UBehaviorTreeComponent* BehaviorComp;

		//blackboard component
		UBlackboardComponent* BlackBoardComp;

		//BlackBoardkeys
		UPROPERTY(EditDefaultsOnly, Category = AI)
		FName LocationToGoKey;

		UPROPERTY(EditDefaultsOnly, Category = AI)
		FName PlayerKey;

		TArray<AActor*> TargetPoints;

		virtual void Possess(APawn* Pawn) override;

		


public:

	

	AAI_Patrol_Controller();

	void SetPlayerCaught(APawn* Pawn);

	int32 CurrentTargetPoint = 0;

	// inline geter functions

	FORCEINLINE UBlackboardComponent* GetBlackboardComponent() const { return BlackBoardComp; }
	FORCEINLINE TArray<AActor*> GetTargetPionts() const { return TargetPoints; }

};
