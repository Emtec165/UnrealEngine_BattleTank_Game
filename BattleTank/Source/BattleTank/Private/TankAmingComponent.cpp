// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAmingComponent.h"


// Sets default values for this component's properties
UTankAmingComponent::UTankAmingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAmingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet) {
	Barrel = BarrelToSet;
}

void UTankAmingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	//Calculate the OutLaunchVelocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace);

	if (bHaveAimSolution) {
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
	else {
		//	nothing
	}
}

void UTankAmingComponent::MoveBarrelTowards(FVector AimDirection) {
	// Work-out difference between current barrel rotation and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"), *AimAsRotator.ToString())

	// Move the berrel
}


