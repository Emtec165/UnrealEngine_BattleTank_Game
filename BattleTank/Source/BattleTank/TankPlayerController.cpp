// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController it's accesable from VS."))

	ATank* ControlledTank = nullptr;
	ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank."), *ControlledTank->GetName())
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is possesing %s tank."), *ControlledTank->GetName())
	}
}

ATank*  ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}


