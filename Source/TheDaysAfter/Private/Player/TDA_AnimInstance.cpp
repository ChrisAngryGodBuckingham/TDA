// Copyright 2017 AngryGod of M.A.G. Studios

#include "TDA_AnimInstance.h"


void UTDA_AnimInstance::UpdateAnimProperties()
{

	APawn* Pawn = TryGetPawnOwner();

	if (Pawn)
	{
		MovementSpeed = Pawn->GetVelocity().Size();
	}

}
