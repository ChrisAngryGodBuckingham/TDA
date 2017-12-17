// Copyright 2017 AngryGod of M.A.G. Studios

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TDA_AnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class THEDAYSAFTER_API UTDA_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MovementSpeed;

	UFUNCTION(BlueprintCallable, Category = "Animations")
	virtual void UpdateAnimProperties();


	
	
};
