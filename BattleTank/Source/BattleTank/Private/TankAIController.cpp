// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);


	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* ControlledTank = Cast<ATank>(GetPawn());
	if (!PlayerTank) { return; }
	if (!ControlledTank) { return; }
	ControlledTank->AimAt(PlayerTank->GetActorLocation());

	// Fire
	ControlledTank->Fire();	// TODO limit firing rate
}
