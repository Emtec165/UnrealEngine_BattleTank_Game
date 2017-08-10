// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	//	How close an AI can get to the player
	UPROPERTY(EditDefaultsOnly)
	float AcceptanceRadius = 3000;	// TODO radius is in cm

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
