// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystem/SlimerAbilitySystemComponent.h"

#include "SlimerAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


UCLASS()
class SLIMEDEFENSE_API USlimerAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	USlimerAttributeSet();

	UPROPERTY(BlueprintReadOnly, Category="Health")
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(USlimerAttributeSet, CurrentHealth)

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(USlimerAttributeSet, MaxHealth)
	
	UPROPERTY(BlueprintReadOnly, Category = "Mana")
	FGameplayAttributeData CurrentMana;
	ATTRIBUTE_ACCESSORS(USlimerAttributeSet, CurrentMana)
	
	UPROPERTY(BlueprintReadOnly, Category = "Mana")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(USlimerAttributeSet, MaxMana)
};
