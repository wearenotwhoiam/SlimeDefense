// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/TowerDefenseWidgetController.h"

void UTowerDefenseWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UTowerDefenseWidgetController::BroadcastInitialValues()
{
}

void UTowerDefenseWidgetController::BindCallbacksToDependencies()
{
}
