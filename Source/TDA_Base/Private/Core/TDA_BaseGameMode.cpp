/*CopyRight 2017 Chris "AngryGod" Buckingham M.A.G.Studios Canada*/

#include "TDA_BaseGameMode.h"
#include "TDA_BaseHUD.h"
#include "TDA_BaseCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATDA_BaseGameMode::ATDA_BaseGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/TDA_BaseCharator_BP"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATDA_BaseHUD::StaticClass();
}
