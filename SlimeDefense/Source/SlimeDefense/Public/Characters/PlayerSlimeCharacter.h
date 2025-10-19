// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/TowerDefenseBaseCharacter.h"
#include "PlayerSlimeCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SLIMEDEFENSE_API APlayerSlimeCharacter : public ATowerDefenseBaseCharacter
{
	GENERATED_BODY()

public:
	APlayerSlimeCharacter();

protected:
	virtual void BeginPlay() override;

#pragma region Components
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* BoxComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character", meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* SlimeMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess= "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

#pragma endregion
};
