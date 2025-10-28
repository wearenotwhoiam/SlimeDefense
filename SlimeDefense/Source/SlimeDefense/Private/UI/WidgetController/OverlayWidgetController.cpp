// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"
#include "UI/Widget/TowerDefenseUserWidget.h"
#include "AbilitySystem/SlimerAbilitySystemComponent.h"
#include "AbilitySystem/SlimerAttributeSet.h"
#include "DebugHelper.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const USlimerAttributeSet* TowerDefenseAttributeSet = CastChecked<USlimerAttributeSet>(AttributeSet);


	OnHealthChanged.Broadcast(TowerDefenseAttributeSet->GetCurrentHealth());
	OnMaxHealthChanged.Broadcast(TowerDefenseAttributeSet->GetMaxHealth());

	OnManaChanged.Broadcast(TowerDefenseAttributeSet->GetCurrentMana());
	OnMaxManaChanged.Broadcast(TowerDefenseAttributeSet->GetMaxMana());

}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const USlimerAttributeSet* TowerDefenseAttributeSet = CastChecked<USlimerAttributeSet>(AttributeSet);

	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		TowerDefenseAttributeSet->GetCurrentHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data) 
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
		);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		TowerDefenseAttributeSet->GetMaxHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxHealthChanged.Broadcast(Data.NewValue);
			}
		);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		TowerDefenseAttributeSet->GetCurrentManaAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnManaChanged.Broadcast(Data.NewValue);
			}
		);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		TowerDefenseAttributeSet->GetMaxManaAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxManaChanged.Broadcast(Data.NewValue);
			}
		);


	Cast<USlimerAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda
	(
		[](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				const FString Msg = FString::Printf(TEXT("GE TAG: %s"), *Tag.ToString());
				Debug::Print(Msg);
			}
		}
	);

}
