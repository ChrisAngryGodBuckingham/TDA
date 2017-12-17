// Copyright 2017 AngryGod of M.A.G. Studios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TheDaysAfterCharacter.h"
#include "TDA_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class THEDAYSAFTER_API ATDA_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	// Reload Player Inventory , call to update iventory widgets in game
	UFUNCTION(BlueprintImplementableEvent)
	void ReloadInventory();
		
	UFUNCTION(BlueprintCallable, Category = "Utilities")
	void AddItemToInventoryByID(FName ID);

	UFUNCTION(BlueprintCallable, Category = "Utilities")
	void CraftItem(FInventoryItem ComponentA, FInventoryItem ComponentB, ATDA_PlayerController* Controller);



	// Return for is useable, if true useable otherwise nullptr
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	class AUseable* CurrentUseable;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)  
	TArray<FInventoryItem> Inventory;

	
protected:

	//void SetupInputComponent(); removed due to double define :)
		
	void Useable();
	
	virtual void SetupInputComponent() override;
	
		
};
