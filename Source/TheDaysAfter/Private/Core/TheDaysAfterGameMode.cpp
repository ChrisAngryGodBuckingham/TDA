// Copyright 2017 AngryGod of M.A.G. Studios
#include "TheDaysAfterGameMode.h"
#include "TheDaysAfterCharacter.h"
#include "Useable.h"
#include "UObject/ConstructorHelpers.h"

ATheDaysAfterGameMode::ATheDaysAfterGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Script/TheDaysAfter.TheDaysAfterCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
