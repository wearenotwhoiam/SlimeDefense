// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"
#include "UI/Widget/TowerDefenseUserWidget.h"

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

	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(TowerDefenseAttributeSet->GetCurrentHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(TowerDefenseAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(TowerDefenseAttributeSet->GetCurrentManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(TowerDefenseAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);

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


void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}


void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);

}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
