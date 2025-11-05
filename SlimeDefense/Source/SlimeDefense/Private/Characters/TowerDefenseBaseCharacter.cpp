
// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TowerDefenseBaseCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/BoxComponent.h"
#include "AbilitySystem/SlimerAbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"

// Sets default values
ATowerDefenseBaseCharacter::ATowerDefenseBaseCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Comp"));
	SetRootComponent(BoxComp);
	BoxComp->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	SkeletalMesh->SetupAttachment(GetRootComponent());
	SkeletalMesh->SetGenerateOverlapEvents(true);
}

UAbilitySystemComponent* ATowerDefenseBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

FVector ATowerDefenseBaseCharacter::GetCombatSocketLocation()
{
	check(SkeletalMesh);
	return this->SkeletalMesh->GetSocketLocation(ProjectileSpawnSocketName);
}

void ATowerDefenseBaseCharacter::InitAbilityActorInfo()
{

}

void ATowerDefenseBaseCharacter::AddCharacterAbilities()
{
	USlimerAbilitySystemComponent* SlimerASC = CastChecked<USlimerAbilitySystemComponent>(AbilitySystemComponent);

	SlimerASC->AddCharacterAbilities(StartupAbilities);
}

void ATowerDefenseBaseCharacter::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void ATowerDefenseBaseCharacter::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1);
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1);

}
