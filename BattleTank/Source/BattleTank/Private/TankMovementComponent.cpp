// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}


void UTankMovementComponent::IntendMoveForward(float Throw) {
	if (!LeftTrack || !LeftTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	// TODO clamp actual throttle value so player can't change axix scaling and move faster
}

void UTankMovementComponent::IntendTurn(float Throw) {
	if (!LeftTrack || !LeftTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	// TODO clamp actual throttle value so player can't change axix scaling and move faster
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed) {
	// No need to call Super. We don't need it right now

	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: %s MoveVelocity %s"), Time, *GetOwner()->GetName(), *MoveVelocity.ToString())
}

