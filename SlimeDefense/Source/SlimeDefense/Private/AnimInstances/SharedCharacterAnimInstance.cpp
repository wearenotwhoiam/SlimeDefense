// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/SharedCharacterAnimInstance.h"
#include "Characters/TowerDefenseBaseCharacter.h"
#include "DebugHelper.h"
#include "GameFramework/FloatingPawnMovement.h"

void USharedCharacterAnimInstance::NativeInitializeAnimation()
{

	OwningPawn = Cast<ATowerDefenseBaseCharacter>(TryGetPawnOwner());
	if (OwningPawn)
	{
		OwningMovementComponent = Cast< UFloatingPawnMovement>(OwningPawn->GetMovementComponent());
	}
	LastVelocity = FVector::ZeroVector;
}

void USharedCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

    if (!OwningPawn || !OwningMovementComponent) return;

	const FVector CurrentVelocity = OwningPawn->GetVelocity();
	GroundSpeed = CurrentVelocity.Size2D();
	bIsMoving = !CurrentVelocity.IsNearlyZero();
	MovementAngle = CalculateDirection(CurrentVelocity, OwningPawn->GetActorRotation());
}