// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "Components/ActorComponent.h"
#include "DoorInteractionComponent.generated.h"

class ATriggerBox;

UENUM()
enum State 
{
	Closed,
	Closing,
	Open,
	Opening
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANTRUM_API UDoorInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorInteractionComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void Alert(FString message, int duration);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	bool isOpen = false;
	bool triggered = false;

	State Door{ Closed };

	UWorld* World;
	AActor* Owner;
	ULocalPlayer* LocalPlayer;
	APlayerController* Player;
	APawn* PlayerPawn;

	UPROPERTY(EditAnywhere)
	FRotator DesiredRotation = FRotator::ZeroRotator;
	FRotator DeltaRotation = FRotator::ZeroRotator;
	FRotator StartRotation = FRotator::ZeroRotator;
	FRotator FinalRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere)
	float TimeToRotate = 1.0f;
	float CurrentRotationTime = 0.0f;

	UPROPERTY(EditAnywhere)
	FRuntimeFloatCurve OpenCurve;

	UPROPERTY(EditAnywhere)
	ATriggerBox* TriggerBox;
};
