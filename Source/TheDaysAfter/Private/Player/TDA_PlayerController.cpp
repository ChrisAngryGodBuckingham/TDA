// Copyright 2017 AngryGod of M.A.G. Studios

#include "TDA_PlayerController.h"
#include "Useable.h"
#include "TDA_GamePlay.h"
#include "TheDaysAfterCharacter.h"
#include "TheDaysAfterGameMode.h"


void ATDA_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();     
	InputComponent->BindAction("Use", IE_Pressed, this, &ATDA_PlayerController::Useable);
}


void ATDA_PlayerController::CraftItem(FInventoryItem ComponentA, FInventoryItem ComponentB, ATDA_PlayerController * Controller)
{

	// Check for Valid Craft Combinations
	for (auto Craft : ComponentB.CraftCombinations)
	{
		if (Craft.ComponentID == ComponentA.ItemID)
		{
			if (Craft.bDestroyComponentA)
			{
				Inventory.RemoveSingle(ComponentA);
			}

			if (Craft.bDestroyComponentB)
			{
				Inventory.RemoveSingle(ComponentB);
			}

			AddItemToInventoryByID(Craft.ProductID);

			ReloadInventory();

		}


	}



}

void ATDA_PlayerController::Useable()
{

	if (CurrentUseable)
	{
		CurrentUseable->Useable(this);
	}
}

void ATDA_PlayerController::AddItemToInventoryByID(FName ID)
{

	ATDA_GamePlay* GameMode = Cast<ATDA_GamePlay>(GetWorld()->GetAuthGameMode());
	
	UDataTable* ItemTable = GameMode->GetItem_DB();

	FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "");
		if (ItemToAdd)
			{

				Inventory.Add(*ItemToAdd);
		
			}


}

