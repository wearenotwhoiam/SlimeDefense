// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Enemy/EnemyBaseCharacter.h"
#include "AbilitySystem/SlimerAbilitySystemComponent.h"
#include "AbilitySystem/SlimerAttributeSet.h"
#include "Components/WidgetComponent.h"
#include "UI/Widget/TowerDefenseUserWidget.h"

AEnemyBaseCharacter::AEnemyBaseCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<USlimerAbilitySystemComponent>("AbilitySystemComponent");
	AttributeSet = CreateDefaultSubobject<USlimerAttributeSet>("AttributeSet");

	HealthBar = CreateDefaultSubobject<UWidgetComponent>("HealthBar");
	HealthBar->SetupAttachment(GetRootComponent());
}

void AEnemyBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	InitAbilityActorInfo();

	if (UTowerDefenseUserWidget* TowerDefenseWidget = Cast<UTowerDefenseUserWidget>(HealthBar->GetUserWidgetObject()))
	{
		TowerDefenseWidget->SetWidgetController(this);
	}

	if (const USlimerAttributeSet* TowerDefenseAS = Cast<USlimerAttributeSet>(AttributeSet))
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(TowerDefenseAS->GetCurrentHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
		);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(TowerDefenseAS->GetCurrentHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
		);

		OnHealthChanged.Broadcast(TowerDefenseAS->GetCurrentHealth());
		OnMaxHealthChanged.Broadcast(TowerDefenseAS->GetMaxHealth());
	};
}

void AEnemyBaseCharacter::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<USlimerAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();

	InitializeDefaultAttributes();
}
