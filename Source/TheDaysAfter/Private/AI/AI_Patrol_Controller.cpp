// Copyright 2017 AngryGod of M.A.G. Studios


#include "AI_Patrol_Controller.h"
#include "AI_Patrol.h"
#include "AI_TargetPoint.h"
#include "TheDaysAfter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"



AAI_Patrol_Controller::AAI_Patrol_Controller()
{

	// Initalize blackbord and behaviortree
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
	BlackBoardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoardComp"));

	// Initialize BlackBoard Keys
	PlayerKey = "Target";
	LocationToGoKey = "LocationToGo";

	CurrentTargetPoint = 0;

}

void AAI_Patrol_Controller::SetPlayerCaught(APawn * Pawn)
{
	if (BlackBoardComp)
	{
		BlackBoardComp->SetValueAsObject(PlayerKey, Pawn);
	}
}

void AAI_Patrol_Controller::Possess(APawn * Pawn)
{
	Super::Possess(Pawn);

	// get character reference
	AAI_Patrol* AICharacter = Cast<AAI_Patrol>(Pawn);

	if (AICharacter)
	{
		if (AICharacter->BehaviorTree->BlackboardAsset)
		{
			BlackBoardComp->InitializeBlackboard(*(AICharacter->BehaviorTree->BlackboardAsset));
		}

		// populate patrolpoint array
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAI_TargetPoint::StaticClass(),TargetPoints);

		BehaviorComp->StartTree(*AICharacter->BehaviorTree);

	}


}