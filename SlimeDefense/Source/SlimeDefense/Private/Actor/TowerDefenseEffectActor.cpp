// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/TowerDefenseEffectActor.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/SlimerAttributeSet.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameplayEffect.h"
#include "AbilitySystemBlueprintLibrary.h"

// Sets default values
ATowerDefenseEffectActor::ATowerDefenseEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}


// Called when the game starts or when spawned
void ATowerDefenseEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void ATowerDefenseEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);

	if (TargetASC == nullptr) return;
	checkf(GameplayEffectClass, TEXT("GameplayEffectClass not set!"));

	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);

	FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.f, EffectContextHandle);
	TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}
