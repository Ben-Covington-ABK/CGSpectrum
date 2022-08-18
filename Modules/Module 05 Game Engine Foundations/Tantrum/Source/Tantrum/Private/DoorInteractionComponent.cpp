// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorInteractionComponent.h"
#include "Engine/TriggerBox.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UDoorInteractionComponent::UDoorInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void m_Alert(FString message, float duration = 5.f)
{
	GEngine->
	AddOnScreenDebugMessage( -1,
		duration,			
		FColor::White,	
		message	
	);
}

// Called when the game starts
void UDoorInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
	//Alert("Moving Door");
	Owner = GetOwner();
	World = GetWorld();
	LocalPlayer = World->GetFirstLocalPlayerFromController();
	Player = World->GetFirstPlayerController();
	PlayerPawn = Player->GetPawn();

	//DesiredRotation = FRotator(0.0f, 0.0f, 0.0f);
	//DeltaRotation = DesiredRotation - Owner->GetActorRotation();
	StartRotation = Owner->GetActorRotation();
	FinalRotation = DesiredRotation + Owner->GetActorRotation();
	//Owner->SetActorRotation(DesiredRotation);
	
}

// Called every frame
void UDoorInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if(TriggerBox && World && PlayerPawn)
	{

		triggered = TriggerBox->IsOverlappingActor(PlayerPawn);

		/*
		if(triggered)
		{
			Door = Door == State::Open ? State::Open : State::Opening;
		}
		else
		{
			Door = Door == State::Closed ? State::Closed : State::Closing;
		}
		*/


		/*
		Door = triggered ? ((CurrentRotationTime < TimeToRotate) ? State::Opening : State::Open)
			: (Door == CurrentRotationTime > 0 ? State::Closing : State::Closed);
		*/
		//Alert(("Door: " + (int)Door), 0.1);

		/*
		switch (Door)
		{
		case Closed:
			Alert("Door Closed", 0.1);
			break;
		case Closing:
			Alert("Door Closing", 0.1);
			break;
		case Open:
			Alert("Door Open", 0.1);
			break;
		case Opening:
			Alert("Door Opening", 0.1);
			break;
		default:
			break;
		}
		*/

		/*
		CurrentRotationTime += Door == State::Opening ? DeltaTime :
			(Door == State::Closing ? -DeltaTime : 0);
		*/
					

		isOpen = CurrentRotationTime < TimeToRotate;
		CurrentRotationTime = CurrentRotationTime +
			(!triggered && CurrentRotationTime > 0 ? -DeltaTime : 
			triggered && isOpen ? DeltaTime : 0);		

		if(true || Door != State::Closed && Door != State::Open)
		{
			float RotationAlpha = FMath::Clamp(CurrentRotationTime / TimeToRotate, 0.0f, 1.0f);
			FRotator CurrentRotation = FMath::Lerp(StartRotation, DesiredRotation, RotationAlpha);
			Owner->SetActorRotation(CurrentRotation);	
		}
	}

	/*
	if(CurrentRotationTime < TimeToRotate)
	{
		if (TriggerBox && GetWorld()->GetFirstLocalPlayerFromController())
		{
			PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
			if (PlayerPawn && TriggerBox->IsOverlappingActor(PlayerPawn))
			{
				CurrentRotationTime += DeltaTime;
				float RotationAlpha = FMath::Clamp(CurrentRotationTime / TimeToRotate, 0.0f, 1.0f);
				FRotator CurrentRotation = FMath::Lerp(StartRotation, DesiredRotation, RotationAlpha);
				GetOwner()->SetActorRotation(CurrentRotation);
			}
		}
	}
	*/
	/*
	AActor* Owner = GetOwner();
	FRotator CurrentRotation = Owner->GetActorRotation();
	bool isAligned = CurrentRotation.Equals(DesiredRotation, 5.0f);
	FString log = "Current: " + CurrentRotation.ToString()
		+ "\nDesired: " + DesiredRotation.ToString() + "\n" 
		+ (isAligned ? "Aligned" : "Not Aligned");
	//Alert(log, 0.1f);
	if (!isAligned)
	{
		CurrentRotation += DeltaRotation * DeltaTime;
		Owner->SetActorRotation(CurrentRotation);
	}
	*/
}

void UDoorInteractionComponent::Alert(FString message, int duration)
{
	// Do
	m_Alert(message, duration);
}

