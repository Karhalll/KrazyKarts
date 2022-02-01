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

	// The number of degrees rotated per second at full control throw [deg/s]
	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 90;

	FVector Velocity;

	float Throttle;
	float SteeringThrow;

	void MoveForward(float Value);
	void MoveRight(float Value);

	void ApplyRotation(float DeltaTime);
	void UpdateLocationFromVelocity(float DeltaTime);
};
