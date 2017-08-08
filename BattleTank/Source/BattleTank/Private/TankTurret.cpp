// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed) {
	//Rotate turret
	auto ClampedRelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto RotationChange = ClampedRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
	UE_LOG(LogTemp, Warning, TEXT("%f"), RawNewRotation)

	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}



