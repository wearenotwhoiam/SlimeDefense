// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/TowerDefenseProjectileSpell.h"
#include "Interactions/CombatInterface.h"
#include "Actor/TowerDefenseProjectile.h"


void UTowerDefenseProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UTowerDefenseProjectileSpell::SpawnProjectile(const FVector ProjectileTargetLocation)
{
	ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo());
	if (CombatInterface)
	{
		const FVector SocketLocation = CombatInterface->GetCombatSocketLocation();

		FRotator Rotation = (ProjectileTargetLocation - SocketLocation).Rotation();
		Rotation.Pitch = 0;

		if (!ProjectileClass) return;

		FTransform SpawnTransform;
		SpawnTransform.SetLocation(SocketLocation);
		SpawnTransform.SetRotation(Rotation.Quaternion());
		//set projectile rotation
		ATowerDefenseProjectile* Projectile = GetWorld()->SpawnActorDeferred<ATowerDefenseProjectile>
			(
				ProjectileClass,
				SpawnTransform,
				GetOwningActorFromActorInfo(),
				Cast<APawn>(GetOwningActorFromActorInfo()),
				ESpawnActorCollisionHandlingMethod::AlwaysSpawn
			);

		//Give projectile a gameplay effect spec for causing damage

		Projectile->FinishSpawning(SpawnTransform);
	}

}
