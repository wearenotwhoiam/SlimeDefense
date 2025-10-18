// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TowerDefenseBaseCharacter.h"

// Sets default values
ATowerDefenseBaseCharacter::ATowerDefenseBaseCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATowerDefenseBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATowerDefenseBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATowerDefenseBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

