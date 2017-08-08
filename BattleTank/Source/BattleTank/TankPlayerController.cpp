// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"


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
		GetControlledTank()->AimAt(HitLocation);
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
		//	Line-trace along LookDirection and se what we hit (up to max range)
		GetLookVectorHitLocation(LookDirection, HitLocation);
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

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const {
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * AimRange);
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility)) {
		HitLocation = HitResult.Location;
		return true;
	}
	else { // Line-trace did't succeed
		HitLocation = FVector(0.f);
		return false;
	}
}
