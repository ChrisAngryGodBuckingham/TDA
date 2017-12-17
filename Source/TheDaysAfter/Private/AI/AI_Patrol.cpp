// Copyright 2017 AngryGod of M.A.G. Studios

#include "AI_Patrol.h"
#include "AI_Patrol_Controller.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"
#include "Engine.h"



// Sets default values
AAI_Patrol::AAI_Patrol()
{
	// init sensors
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->SetPeripheralVisionAngle(90.f);
 	
}

// Called when the game starts or when spawned
void AAI_Patrol::BeginPlay()
{
	Super::BeginPlay();
	
	if (PawnSensingComp)
	{
		PawnSensingComp->OnSeePawn.AddDynamic(this, &AAI_Patrol::OnPlayerCaught);
	}
}


// Called to bind functionality to input
void AAI_Patrol::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAI_Patrol::OnPlayerCaught(APawn * Pawn)
{
	// get player reference
	AAI_Patrol_Controller* AIController = Cast<AAI_Patrol_Controller>(GetController());

	if (AIController)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You have been caught"));
		AIController->SetPlayerCaught(Pawn);
	}

}

