// Copyright 2017 AngryGod of M.A.G. Studios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Useable.generated.h"

UCLASS()
class THEDAYSAFTER_API AUseable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUseable();


	// Called when player triggers Useable allows designers to use custom pickup via BPs
	UFUNCTION(BlueprintImplementableEvent, Category = "Usable")
		void Useable(APlayerController* Controller);  

	// set propertext for pickups
	UPROPERTY(EditDefaultsOnly)
		FString Name;
	UPROPERTY(EditDefaultsOnly)
		FString Action;
	
	UFUNCTION(BlueprintCallable, Category = "Usable")
		FString GetUseText() const { return FString::Printf(TEXT("%s : Press E tp %s"), *Name, *Action); }


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


		
};
