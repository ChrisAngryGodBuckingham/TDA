// Copyright 2017 AngryGod of M.A.G. Studios

#include "BTSelectPatrolPoint.h"
#include "AI_TargetPoint.h"
#include "AI_Patrol_Controller.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UBTSelectPatrolPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8 * NodeMemory)
{
	AAI_Patrol_Controller* AICon = Cast<AAI_Patrol_Controller>(OwnerComp.GetAIOwner());

	if (AICon)
	{
		// get bb component
		UBlackboardComponent* BlackBoardComp = AICon->GetBlackboardComponent();
		// check where ai is
		AAI_TargetPoint* CurrentPoint = Cast<AAI_TargetPoint>(BlackBoardComp->GetValueAsObject("LocationToGo"));
		// get all points to go
		TArray<AActor*> AvailableTargetPoints = AICon->GetTargetPionts();
		// get next Target point
		AAI_TargetPoint* NextTargetPoint = nullptr;

		if (AICon->CurrentTargetPoint != AvailableTargetPoints.Num() -1)
		{
			NextTargetPoint = Cast<AAI_TargetPoint>(AvailableTargetPoints[++AICon->CurrentTargetPoint]);
		}

		else  // no points left to go to
		{
			NextTargetPoint = Cast<AAI_TargetPoint>(AvailableTargetPoints[0]);
			AICon->CurrentTargetPoint = 0;
		}

		BlackBoardComp->SetValueAsObject("LocationToGo", NextTargetPoint);

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}



