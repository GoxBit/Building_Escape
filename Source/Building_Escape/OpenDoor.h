// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DelataTime);

private:
	float InitialYaw;
	float CurrentYaw;

	UPROPERTY(EditAnywhere)
	float OpenAngle = 90.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
	AActor* ActorThatOpen;

	float DoorLastOPen = 0.f;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = .5f;

	UPROPERTY(EditAnywhere)
	float DoorOpenSpeed = .8f;

	UPROPERTY(EditAnywhere)
	float DoorCloseSpeed = 2.f;
};
