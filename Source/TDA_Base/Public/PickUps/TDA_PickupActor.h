// CopyRight 2017 Chris "AngryGod" Buckingham M.A.G. Studios Canada

#pragma once

#include "Engine.h"
#include "Coreminimal.h"
#include "GameFramework/Actor.h"
#include "TDA_PickupActor.generated.h"

UCLASS()
class TDA_BASE_API ATDA_PickupActor : public AActor
{
	GENERATED_BODY()
	
public:	

	/* Sets default values for this actor's properties*/
	ATDA_PickupActor();

	/*Called every frame, Delta time = 1/FPS */
	virtual void Tick(float DeltaTime) override;

	/*Called when player enters collision component -trigger- of pickup*/
	UFUNCTION()
	void OnPlayerTriggerPickUp(UPrimitiveComponent* OverLappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult&SweepResult);




protected:

	/* Called when the game starts or when spawned*/
	virtual void BeginPlay() override;

	/*Root scene component*/
	UPROPERTY(EditAnywhere)
		USceneComponent* PickupRoot;

	/*Collision component used for triggering pickup*/
	UPROPERTY(EditAnywhere)
		UShapeComponent* PickupTrigger;

	/*StaicMesh for pickup*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* PickupMesh;

	/*Pickup ID# from Item Database*/
	UPROPERTY(Editanywhere, BlueprintReadWrite)
		FName ItemID;

	/*Check type of pickup*/
	UPROPERTY(Editanywhere, BlueprintReadWrite)
		bool IsClothing;
	UPROPERTY(Editanywhere, BlueprintReadWrite)
		bool IsWeapon;

	/*XP value of pickup*/
	UPROPERTY(Editanywhere, BlueprintReadWrite)
		int32 XPValue;


};
