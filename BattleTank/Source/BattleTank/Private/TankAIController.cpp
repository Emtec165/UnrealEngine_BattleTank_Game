// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAmingComponent.h"
#include "Tank.h"	// so we can implement OnDeath method
//	Depends on movement component via pathfinding system

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::SetPawn(APawn * InPawn) {
	Super::SetPawn(InPawn);
	if (InPawn) {
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}

void ATankAIController::OnPossessedTankDeath() {
	UE_LOG(LogTemp, Warning, TEXT("Tank death recived by AI controller"))
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	TankAmingComponent = GetPawn()->FindComponentByClass<UTankAmingComponent>();
	
	if (!ensure(TankAmingComponent) || !ensure(PlayerTank)) { return; }
	MoveToActor(PlayerTank, AcceptanceRadius);
	TankAmingComponent->AimAt(PlayerTank->GetActorLocation());
	if (CanAIFire){ // TODO remove before realeasing game
		if (TankAmingComponent->GetFiringState() == EFiringStatus::Locked){
			TankAmingComponent->Fire();
		}
	}
}
