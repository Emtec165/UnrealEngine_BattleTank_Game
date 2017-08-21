// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAmingComponent;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn* InPawn) override;

	UTankAmingComponent* TankAmingComponent = nullptr;

	UFUNCTION()
	void OnPossessedTankDeath();

	UPROPERTY(EditDefaultsOnly)
	bool CanAIFire = true;

	//	How close an AI can get to the player
	UPROPERTY(EditDefaultsOnly)
	float AcceptanceRadius = 8000;	// TODO radius is in cm
};
