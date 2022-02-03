// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GoKartMovementComponent.h"
#include "GoKartMovementReplicator.h"
#include "GoKart.generated.h"


UCLASS()
class KRAZYKARTS_API AGoKart final : public APawn
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
	UPROPERTY(VisibleAnywhere)
	UGoKartMovementComponent* MovementComponent;
	UPROPERTY(VisibleAnywhere)
	UGoKartMovementReplicator* MovementReplicator;

	void MoveForward(float Value);
	void MoveRight(float Value);
};
