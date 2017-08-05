// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	ATank* ControlledTank = nullptr;
	ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("PlayerController not possesing a tank."), *ControlledTank->GetName())
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is possesing %s tank."), *ControlledTank->GetName())
	}
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::PlayerTick(DeltaTime);
	//	TODO AimTowardsCrosshair();
}

ATank*  ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) { return; }
	
	//	Get world location if linetrace trought crosshair
	//	if it hits the landscape
		//	tell controlled tank to aim at this point
}


