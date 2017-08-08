// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank) { UE_LOG(LogTemp, Error, TEXT("AIContoller not possesing a tank.")) }
	else { UE_LOG(LogTemp, Warning, TEXT("AIContoller is possesing %s tank."), *ControlledTank->GetName()) }

	ATank* PlayerTank = GetPlayerTank();
	if (!PlayerTank) { UE_LOG(LogTemp, Error, TEXT("AIContoller didn't found PlayerTank.")) }
	else { UE_LOG(LogTemp, Warning, TEXT("AIContoller found PlayerTank. Its name is %s."), *PlayerTank->GetName()) }
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	ATank* PlayerTank = GetPlayerTank();
	if (!GetControlledTank()) { return; }
	if (!PlayerTank) { return; }
	GetControlledTank()->AimAt(PlayerTank->GetActorLocation());
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
