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

protected:
	virtual void BeginPlay() override;
	
};
