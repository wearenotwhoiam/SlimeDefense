// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Characters/TowerDefenseBaseCharacter.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "EnemyBaseCharacter.generated.h"
/**
 * 
 */
class UWidgetComponent;

UCLASS()
class SLIMEDEFENSE_API AEnemyBaseCharacter : public ATowerDefenseBaseCharacter
{
	GENERATED_BODY()

public:
	AEnemyBaseCharacter();

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxHealthChanged;

protected:
	void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;
};
