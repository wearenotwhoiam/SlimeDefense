// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PlayerSlimeCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/BoxComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "Components/Input/SlimerInputComponent.h"
#include "SlimerGameplayTags.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/FloatingPawnMovement.h"

#include "DebugHelper.h"

APlayerSlimeCharacter::APlayerSlimeCharacter()
{
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Comp"));
	SetRootComponent(BoxComp);

	SlimeMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	SlimeMesh->SetupAttachment(GetRootComponent());
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));
	MovementComponent->MaxSpeed = 500.f;
}

void APlayerSlimeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
	check(Subsystem);
	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	USlimerInputComponent* SlimerInputComponent = CastChecked<USlimerInputComponent>(PlayerInputComponent);

	SlimerInputComponent->BindNativeInputAction(InputConfigDataAsset, SlimerGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);

	SlimerInputComponent->BindNativeInputAction(InputConfigDataAsset, SlimerGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	SlimerInputComponent->BindNativeInputAction(InputConfigDataAsset, SlimerGameplayTags::InputTag_Move, ETriggerEvent::Ongoing, this, &ThisClass::Input_Move);


}

void APlayerSlimeCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerSlimeCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementInput = InputActionValue.Get<FVector2D>();

	const FRotator CameraYaw(0.f, Controller->GetControlRotation().Yaw, 0.f);
	const FVector Forward = CameraYaw.RotateVector(FVector::ForwardVector);
	const FVector Right = CameraYaw.RotateVector(FVector::RightVector);
	const FVector MoveDir = (Forward * MovementInput.Y + Right * MovementInput.X).GetSafeNormal();

	// Use AddMovementInput instead - this properly sets velocity!
	AddMovementInput(MoveDir, 1.0f);

	// Rotate to camera yaw
	if (!MovementInput.IsNearlyZero())
	{
		const FRotator TargetRotation = CameraYaw;
		const FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), TargetRotation,
			GetWorld()->GetDeltaSeconds(), 5.f);
		SetActorRotation(NewRotation);
	}
}
void APlayerSlimeCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxis = InputActionValue.Get<FVector2D>();

	if (LookAxis.X != 0.f)
	{
		AddControllerYawInput(LookAxis.X);
	}
	if (LookAxis.Y != 0.f)
	{
		AddControllerPitchInput(-LookAxis.Y);
	}
}
