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
	AimTowardsCrosshair();
}

ATank*  ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) { return; }
	
	FVector HitLocation; //	Out parameter
	if (GetSightRayHitLocatoon(HitLocation)) {
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString())
		//	Get world location of linetrace trought crosshair
		//	if it hits the landscape
			//	tell controlled tank to aim at this point
	}
}

bool ATankPlayerController::GetSightRayHitLocatoon(FVector &HitLocation) const {
	//	Find crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLoaction, ViewportSizeY * CrosshairYLoaction);

	// "De-project" the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString())
	}

	//HitLocation = FVector(1.f, 2.f, 3.f);
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	FVector CameraWorldLocation;  // We dont use it but must be present..
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection);
}
