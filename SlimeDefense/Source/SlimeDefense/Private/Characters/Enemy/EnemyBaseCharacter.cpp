// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Enemy/EnemyBaseCharacter.h"
#include "AbilitySystem/SlimerAbilitySystemComponent.h"
#include "AttributeSet.h"

AEnemyBaseCharacter::AEnemyBaseCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<USlimerAbilitySystemComponent>("AbilitySystemComponent");
	AttributeSet = CreateDefaultSubobject<UAttributeSet>("AttributeSet");

}