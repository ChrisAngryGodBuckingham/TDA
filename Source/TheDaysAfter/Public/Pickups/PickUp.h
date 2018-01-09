// Copyright 2017 AngryGod of M.A.G. Studios
#pragma once

#include "CoreMinimal.h"
#include "Useable.h"
#include "PickUp.generated.h"

/**
 * 
 */
UCLASS()
class THEDAYSAFTER_API APickUp : public AUseable
{
	GENERATED_BODY()
	
public:

	APickUp();
	UFUNCTION(BlueprintImplementableEvent)
	void OnUsed();
	
	

protected:
	// pickup components
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* PickupMesh;
	
	UPROPERTY(Editanywhere, BlueprintReadWrite)
	FName ItemID;

	UPROPERTY(Editanywhere, BlueprintReadWrite)
	bool IsClothing;
	
	UPROPERTY(Editanywhere, BlueprintReadWrite)
	bool IsWeapon;
	
	UPROPERTY(Editanywhere, BlueprintReadWrite)
	int32 XPValue;

	UPROPERTY(Editanywhere, BlueprintReadWrite)
	int32 Value;
	
};
