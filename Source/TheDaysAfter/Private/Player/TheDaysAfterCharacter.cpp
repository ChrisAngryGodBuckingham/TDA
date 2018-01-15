// Copyright 2017 AngryGod of M.A.G. Studios

#include "TheDaysAfterCharacter.h"
#include "TheDaysAfterGameMode.h"
#include "Useable.h"
#include "Target.h"
#include "Camera/CameraComponent.h"
#include "TDA_PlayerController.h"


//////////////////////////////////////////////////////////////////////////
// ATheDaysAfterCharacter

ATheDaysAfterCharacter::ATheDaysAfterCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->RelativeLocation = FVector(300.0f, 1.75f, 64.f); // Position the camera
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named TDA_Character_BP (to avoid direct content references in C++)

	
	// Create a First PersonCameraComponent	
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCamera->SetupAttachment(GetCapsuleComponent());
	FirstPersonCamera->RelativeLocation = FVector(39.56f, 1.75f, 64.f); // Position the camera
	FirstPersonCamera->bUsePawnControlRotation = true;

	TopMesh = CreateDefaultSubobject<USkeletalMeshComponent>(FName("TopMesh"));
	TopMesh->SetupAttachment(GetMesh());
	BottomMesh = CreateDefaultSubobject<USkeletalMeshComponent>(FName("BottomMesh"));
	BottomMesh->SetupAttachment(GetMesh());
	HatMesh = CreateDefaultSubobject<USkeletalMeshComponent>(FName("HatMesh"));
	HatMesh->SetupAttachment(GetMesh());


	

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCamera);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->RelativeRotation = FRotator(1.9f, -19.19f, 5.2f);
	Mesh1P->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);
	/*
	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	FP_Gun->SetupAttachment(RootComponent);

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);

	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P, FP_Gun, and VR_Gun 
	// are set in the derived blueprint asset named MyCharacter to avoid direct content references in C++.

	*/
}

//////////////////////////////////////////////////////////////////////////
// Input

void ATheDaysAfterCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	// PlayerInputComponent->BindAction("Use", IE_Pressed, this, &ATheDaysAfterCharacter::Use);
	PlayerInputComponent->BindAxis("MoveForward", this, &ATheDaysAfterCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATheDaysAfterCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ATheDaysAfterCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ATheDaysAfterCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ATheDaysAfterCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ATheDaysAfterCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ATheDaysAfterCharacter::OnResetVR);
	
	// On Fire
	// PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ATheDaysAfterCharacter::OnFire);


}
/*
void ATheDaysAfterCharacter::OnFire()
{
	
}

void ATheDaysAfterCharacter::Use()
{

}
*/
void ATheDaysAfterCharacter::BeginPlay()
{
		Super::BeginPlay();

		TopMesh->SetMasterPoseComponent(GetMesh());
		BottomMesh->SetMasterPoseComponent(GetMesh());
		HatMesh->SetMasterPoseComponent(GetMesh());
	
}

// implment tick function for pickups
void ATheDaysAfterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckForUseable();

}

// implement Pickups
void ATheDaysAfterCharacter::CheckForUseable()
{

	FHitResult HitResult;

	FVector StartTrace = FollowCamera->GetComponentLocation();
	FVector EndTrace = (FollowCamera->GetForwardVector() * 450) + StartTrace;

	// make sure we dont trace to the player
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	ATDA_PlayerController* Controller = Cast<ATDA_PlayerController>(GetController());
	if (!Controller)
		return;

	// Cast using Visibility channel can change to custom if needed
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Visibility, QueryParams) && Controller)
	{

		// Is item usable? otherwise return nullpointer
		if (AUseable* Useable = Cast<AUseable>(HitResult.GetActor()))
		{
			Controller->CurrentUseable = Useable;
			return;
		}


	}

	// return null on fail
	Controller-> CurrentUseable = nullptr; 


}

void ATheDaysAfterCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ATheDaysAfterCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void ATheDaysAfterCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void ATheDaysAfterCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ATheDaysAfterCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ATheDaysAfterCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ATheDaysAfterCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

/*removed until finished

void ATheDaysAfterCharacter::OnFire()
{
	// try to fire projectile
	if (ProjectileClass != NULL)
	{
		const FRotator SpawnRotation = GetControlRotation();

		// muzzleoffset is in camera space transfer to world space before offsetting to find final position
		const FVector SpawnLocation = GetActorLocation() + SpawnRotation.RotateVector(GunOffset);

		UWorld* const world = GetWorld();
		if (World != Null)
		{
			// spawn projectile at muzzle

		}
	}

	// try to play sound if specified
	if (FireSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	// try to play fireing anim if specified
	if (FireAnimation != NULL)
	{
		// get anim object for the mesh
		UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
		if (AnimInstance != NULL)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}

	FHitResult HitResult = new FHitResult();
	FVector StartTrace = FollowCameraComponent->GetComponentLocation();
	FVector ForwardVector = FollowCameraComponent->GetForwardVector();
	FVector EndTrace = ((ForwardVector * 2000.f) + StartTrace);
	FCollisionQueryParams* TraceParams = new FCollisionQueryParams();

	if (GetWorld()->LineTraceSingle(*HitResult, StartTrace, EndTrace, ECC_Visibility, *TraceParams))
	{
	//	DrawrDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Blue, false, 5.f);

		ATarget* TestTarget = Cast <ATarget>(HitResult->Actor.Get());

		if (TestTarget != NULL && !TestTarget->IsPendingKill())
		{
			TestTarget->DamageTarget(50.f);
		}

	}
}
*/