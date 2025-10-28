// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/TowerDefenseUserWidget.h"

void UTowerDefenseUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
