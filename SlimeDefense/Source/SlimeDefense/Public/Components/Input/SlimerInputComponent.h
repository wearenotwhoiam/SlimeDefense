// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"

#include "SlimerInputComponent.generated.h"


UCLASS()
class SLIMEDEFENSE_API USlimerInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* Context, CallbackFunc Func);

	template<class UserObject, typename PressedFuncType, typename ReleasedFuncType, typename HeldFuncType>
	void BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject, PressedFuncType InputPressedFunc, ReleasedFuncType InputReleasedFunc, HeldFuncType HeldFunc);
};

template<class UserObject, typename CallbackFunc>
inline void USlimerInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* Context, CallbackFunc Func)
{

	checkf(InInputConfig, TEXT("Input config data asset is null, can not proceed with binding"));

	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(FoundAction, TriggerEvent, Context, Func);
	}
}

template<class UserObject, typename PressedFuncType, typename ReleasedFuncType, typename HeldFuncType>
inline void USlimerInputComponent::BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, HeldFuncType HeldFunc)
{
	checkf(InInputConfig, TEXT("Input config data asset is null, cannot proceed with binding"));

	for (const FSlimerInputActionConfig& Action : InInputConfig->AbilityInputActions)
	{
		if(Action.InputAction && Action.InputTag.IsValid())
		{
			if (PressedFunc)
			{
				BindAction(Action.InputAction, ETriggerEvent::Started, ContextObject, PressedFunc, Action.InputTag);
			}
			if (ReleasedFunc)
			{
				BindAction(Action.InputAction, ETriggerEvent::Completed, ContextObject, ReleasedFunc, Action.InputTag);

			}
			if (HeldFunc)
			{
				BindAction(Action.InputAction, ETriggerEvent::Ongoing, ContextObject, HeldFunc, Action.InputTag);

			}
		}
	}
}
