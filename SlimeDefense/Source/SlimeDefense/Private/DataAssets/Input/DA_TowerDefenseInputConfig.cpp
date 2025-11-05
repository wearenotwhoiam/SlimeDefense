// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/Input/DA_TowerDefenseInputConfig.h"
#include "DebugHelper.h"

const UInputAction* UDA_TowerDefenseInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InInputTag, bool bLogNotFound) const
{
	for (const FTowerDefenseInputAction& Action : AbilityInputActions)
	{
		if (Action.InputTag == InInputTag && Action.InputAction)
		{
			return Action.InputAction;
		}
	}
	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Could not find AbilityInputAction for InputTag [%s] in InputConfig [%s]"),
			*InInputTag.ToString(), *GetNameSafe(this));
	}

	return nullptr;

}
