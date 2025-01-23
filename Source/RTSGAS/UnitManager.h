// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HISM_Units.h"
#include "UnitManager.generated.h"

UCLASS()
class RTSGAS_API AUnitManager : public AActor
{
	//Manages all abilities of all units.

	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUnitManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void ChangeColor(int32 UnitIndex, FColor Color);

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UHISM_Units* HISM_Units;

};
