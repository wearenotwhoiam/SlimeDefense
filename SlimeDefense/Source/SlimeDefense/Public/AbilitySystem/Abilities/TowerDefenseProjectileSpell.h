// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/TowerDefenseGameplayAbility.h"
#include "TowerDefenseProjectileSpell.generated.h"

class ATowerDefenseProjectile;
/**
 * 
 */
UCLASS()
class SLIMEDEFENSE_API UTowerDefenseProjectileSpell : public UTowerDefenseGameplayAbility
{
	GENERATED_BODY()
	
protected:

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void SpawnProjectile(const FVector ProjectileTargetLocation);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<ATowerDefenseProjectile> ProjectileClass;

};
