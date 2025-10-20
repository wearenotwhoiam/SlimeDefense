// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/CharacterBaseAnimInstance.h"
#include "SharedCharacterAnimInstance.generated.h"

class ATowerDefenseBaseCharacter;

UCLASS()
class SLIMEDEFENSE_API USharedCharacterAnimInstance : public UCharacterBaseAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:

	UPROPERTY()
	ATowerDefenseBaseCharacter* OwningPawn;

	UPROPERTY()
	class UFloatingPawnMovement* OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bIsAccelerating;

	UPROPERTY()
	FVector LastVelocity;

};
