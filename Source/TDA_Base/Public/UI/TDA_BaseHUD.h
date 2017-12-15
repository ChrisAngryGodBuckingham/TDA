/*CopyRight 2017 Chris "AngryGod" Buckingham M.A.G.Studios Canada*/
#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TDA_BaseHUD.generated.h"

UCLASS()
class ATDA_BaseHUD : public AHUD
{
	GENERATED_BODY()

public:
	ATDA_BaseHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

