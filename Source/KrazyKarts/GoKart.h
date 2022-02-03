// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GoKartMovementComponent.h"

#include "GoKart.generated.h"


USTRUCT()
struct FGoKartState
{
	GENERATED_BODY()

	UPROPERTY()
	FTransform Transform;
	UPROPERTY()
	FVector Velocity;
	
	UPROPERTY()
	FGoKartMove LastMove;
};

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
	UPROPERTY(EditAnywhere)
	UGoKartMovementComponent* MovementComponent;
	
	UPROPERTY(ReplicatedUsing=OnRep_ServerState)
	FGoKartState ServerState;

	TArray<FGoKartMove> UnacknowledgedMoves;

	UFUNCTION()
	void OnRep_ServerState();
	
	void ClearAcknowledgeMoves(FGoKartMove LastMove);

	void MoveForward(float Value);
	void MoveRight(float Value);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_SendMove(FGoKartMove Move);
};
