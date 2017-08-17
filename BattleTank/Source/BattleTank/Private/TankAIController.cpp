// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAmingComponent.h"
//	Depends on movement component via pathfinding system

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	TankAmingComponent = GetPawn()->FindComponentByClass<UTankAmingComponent>();
	
	if (!ensure(TankAmingComponent) || !ensure(PlayerTank)) { return; }
	MoveToActor(PlayerTank, AcceptanceRadius);
	TankAmingComponent->AimAt(PlayerTank->GetActorLocation());
	if (CanAIFire){
		TankAmingComponent->Fire();
	}
}
