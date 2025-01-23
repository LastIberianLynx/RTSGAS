// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitManager.h"


// Sets default values
AUnitManager::AUnitManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Scene);

	HISM_Units = CreateDefaultSubobject<UHISM_Units>(TEXT("Units"));
	//HISM_Units->SetupAttachment(CollisionMesh);
	HISM_Units->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	HISM_Units->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	HISM_Units->CanCharacterStepUp(false);
	HISM_Units->SetCastShadow(false);
	HISM_Units->SetComponentTickEnabled(false);
	HISM_Units->NumCustomDataFloats = 3;
	HISM_Units->SetGenerateOverlapEvents(false);
	HISM_Units->SetSimulatePhysics(false);


}

// Called when the game starts or when spawned
void AUnitManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUnitManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUnitManager::ChangeColor(int32 UnitIndex, FColor Color)
{
	
	HISM_Units->SetCustomDataValue(UnitIndex, 0, Color.R);
	HISM_Units->SetCustomDataValue(UnitIndex, 1, Color.G);
	HISM_Units->SetCustomDataValue(UnitIndex, 2, Color.B);

	HISM_Units->MarkRenderStateDirty();
}

