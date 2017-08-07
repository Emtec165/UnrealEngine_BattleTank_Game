// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	//	start the tank moving the barrel so that a shot would hit where
	//	the crosshair intersects the world
	void AimTowardsCrosshair();

	bool GetSightRayHitLocatoon(FVector&) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLoaction = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLoaction = 0.33333;

	bool GetLookDirection(FVector2D, FVector&) const;
};
