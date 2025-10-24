
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

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	SkeletalMesh->SetupAttachment(GetRootComponent());
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
