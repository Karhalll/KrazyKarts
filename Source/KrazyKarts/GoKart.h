// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GoKart.generated.h"

UCLASS()
class KRAZYKARTS_API AGoKart : public APawn
{
	GENERATED_BODY()

public:
	AGoKart();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// The mass of the car [kg].
	UPROPERTY(EditAnywhere)
	float Mass = 1000;

	// The force applied to the car when the throttle is fully down [N].
	UPROPERTY(EditAnywhere)
	float MaxDrivingForce = 10000;

	// Minimum radius of the car turning circle at full lock [m]
	UPROPERTY(EditAnywhere)
	float MinTurningRadius = 10;

	// Higher means more drag [kg/m].
	UPROPERTY(EditAnywhere)
	float DragCoefficient = 16;

	// Higher means more rolling resistance.
	UPROPERTY(EditAnywhere)
	float RollingResistanceCoefficient = 0.015;

	FVector Velocity;

	float Throttle;
	float SteeringThrow;
	
	FVector GetResistance();
	FVector GetRollingResistance();
	
	void MoveForward(float Value);
	void MoveRight(float Value);

	void ApplyRotation(float DeltaTime);
	void UpdateLocationFromVelocity(float DeltaTime);
};
