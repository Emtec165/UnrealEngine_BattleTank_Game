// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed) {
	// Move the berrel
	auto ClampedRelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto ElevationChange = ClampedRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto ClampedRawNewElevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegress, MaxElevationDegress);

	SetRelativeRotation(FRotator(ClampedRawNewElevation, 0, 0));
}

