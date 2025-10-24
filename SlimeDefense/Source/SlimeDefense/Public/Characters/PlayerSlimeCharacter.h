// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/TowerDefenseBaseCharacter.h"
#include "GameplayTagContainer.h"

#include "PlayerSlimeCharacter.generated.h"

struct FInputActionValue;

UCLASS()
class SLIMEDEFENSE_API APlayerSlimeCharacter : public ATowerDefenseBaseCharacter
{
	GENERATED_BODY()

public:
	APlayerSlimeCharacter();
protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;

	virtual void InitAbilityActorInfo() override;

#pragma region Components

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess= "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	class UFloatingPawnMovement* MovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	class UCombatComponent* CombatComponent;
#pragma endregion


#pragma region Input
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess = "true"))
	class UDataAsset_InputConfig* InputConfigDataAsset;

	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Locomotion", meta = (AllowPrivateAccess = "true"))
	float MaxSlimeWalkSpeed = 250.f;
#pragma endregion

private:

	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);
};
