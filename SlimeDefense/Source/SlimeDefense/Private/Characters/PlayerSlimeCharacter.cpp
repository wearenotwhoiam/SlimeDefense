// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PlayerSlimeCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/BoxComponent.h"

#include "DebugHelper.h"

APlayerSlimeCharacter::APlayerSlimeCharacter()
{
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Comp"));
	BoxComp->SetupAttachment(GetRootComponent());
	SetRootComponent(BoxComp);

	SlimeMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	SlimeMesh->SetupAttachment(GetRootComponent());

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}

void APlayerSlimeCharacter::BeginPlay()
{
	Super::BeginPlay();

	Debug::Print("YOYOYOYOY");
}
