// Copyright 2017 AngryGod of M.A.G. Studios
#include "PickUp.h"

// implement mesh for pickups also add item ID
APickUp::APickUp()
{
	
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");
	ItemID = FName("Please enter Item ID");
	IsClothing = false;
	IsWeapon = false;
	XPValue = 10;
	

}



