// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Interactions/CombatInterface.h"
#include "GameFramework/Pawn.h"
#include "TowerDefenseBaseCharacter.generated.h"


class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayAbility;

UCLASS()
class SLIMEDEFENSE_API ATowerDefenseBaseCharacter : public APawn, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATowerDefenseBaseCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* BoxComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character", meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;


	UPROPERTY(EditAnywhere, Category = "Combat")
	FName ProjectileSpawnSocketName;

	virtual FVector GetCombatSocketLocation() override;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	virtual void InitAbilityActorInfo();

	void AddCharacterAbilities();
private:

	UPROPERTY(EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;



};
