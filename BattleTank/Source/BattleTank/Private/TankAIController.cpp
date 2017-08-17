// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAmingComponent.h"
#include "Tank.h"
//	Depends on movement component via pathfinding system

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	TankAmingComponent = GetPawn()->FindComponentByClass<UTankAmingComponent>();
	
	if (!ensure(TankAmingComponent) || !ensure(PlayerTank)) { return; }
	MoveToActor(PlayerTank, AcceptanceRadius);
	TankAmingComponent->AimAt(PlayerTank->GetActorLocation());

	//	TODO fix firing
	//ControlledTank->Fire();	// TODO limit firing rate
}
