// Copyright 2017 AngryGod of M.A.G. Studios

#pragma once


#include "TheDaysAfter.h"
#include "BTSelectPatrolPoint.generated.h"


UCLASS()
class THEDAYSAFTER_API UBTSelectPatrolPoint : public UBTTaskNode
{

	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	
	
};
