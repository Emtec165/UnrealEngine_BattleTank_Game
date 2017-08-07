// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankAmingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAmingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAmingComponent();

	void SetBarrelReference(UStaticMeshComponent*);

	//	TODO add SetTurretReference

	void AimAt(FVector, float);

private:	
	UStaticMeshComponent* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
