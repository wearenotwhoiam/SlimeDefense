// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"

#define TRACE_LENGTH 80000.f

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SLIMEDEFENSE_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatComponent();    
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Combat")
	FORCEINLINE FVector GetHitTarget() const { return HitTarget; }
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void TraceUnderCrosshairs(FHitResult& TraceHitResult);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
	FVector HitTarget;
};
