// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/TowerDefenseUserWidget.h"

void UTowerDefenseUserWidget::SetWidgetControlller(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}

//void UTowerDefenseUserWidget::WidgetControllerSet()
//{
//}
