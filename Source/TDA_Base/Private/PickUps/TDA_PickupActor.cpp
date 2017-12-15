// CopyRight 2017 Chris "AngryGod" Buckingham M.A.G. Studios Canada

#include "TDA_PickupActor.h"


/* Sets default values*/
ATDA_PickupActor::ATDA_PickupActor()
{
 	/* Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.*/
	PrimaryActorTick.bCanEverTick = true;

	/*Pickup Root*/
	PickupRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PickupRoot"));
	RootComponent = PickupRoot;

	/*Pickup Mesh*/
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	PickupMesh->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	/*Pickup Trigger*/
	PickupTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("PickupTrigger"));
	PickupTrigger->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	PickupTrigger->bGenerateOverlapEvents = true;
	PickupTrigger->OnComponentBeginOverlap.AddDynamic(this, &ATDA_PickupActor::OnPlayerTriggerPickUp);
	PickupTrigger->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);


	/*ID # in Item DB*/
	ItemID = FName("Please enter Item ID");

	/*Set default types*/
	IsClothing = false;
	IsWeapon = false;
	
	/*XP Value in Item DB*/
	XPValue = 10;
}

/* Called when the game starts or when spawned*/
void ATDA_PickupActor::BeginPlay()
{
	Super::BeginPlay();
	
}

/* Called every frame*/
void ATDA_PickupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();

	NewLocation.Z += (DeltaTime * 100.f);

	SetActorLocation(NewLocation);


}

/*Called when player enters collision component -trigger- of pickup  TODO add code for adding to inventory ect.*/
void ATDA_PickupActor::OnPlayerTriggerPickUp(UPrimitiveComponent * OverLappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	Destroy();
}

