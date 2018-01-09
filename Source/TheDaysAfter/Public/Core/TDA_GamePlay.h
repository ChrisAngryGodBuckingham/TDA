// Copyright 2017 AngryGod of M.A.G. Studios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TheDaysAfterCharacter.h"
#include "TheDaysAfterGameMode.h"
#include "TDA_GamePlay.generated.h"

/**
 * 
 */
UCLASS()
class THEDAYSAFTER_API ATDA_GamePlay : public AGameMode
{
	GENERATED_BODY()

public:

		class UDataTable* GetItem_DB() const { return Item_DB; }
		

protected:

	UPROPERTY(EditDefaultsOnly)
		class UDataTable* Item_DB;

	
	
	
	
	
};
