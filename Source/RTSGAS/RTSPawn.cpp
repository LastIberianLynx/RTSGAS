// Fill out your copyright notice in the Description page of Project Settings.

#include "RTSPawn.h"
#include "UnitManager.h"
#include "MyAbilitySystemComponent.h"
#include "MyChangeColorAbility.h"



// Sets default values
ARTSPawn::ARTSPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UMyAbilitySystemComponent>(TEXT("AbilitySystemComp"));


}

// Called when the game starts or when spawned
void ARTSPawn::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComponent) {

		for (TSubclassOf<UGameplayAbility>& Ability : DefaultAbilities) {
			if (Ability) {
				AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(Ability, 1, static_cast<int32>(EGASAbilityInputID::Confirm), this));
			}
		}
	}
	
}

// Called every frame
void ARTSPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARTSPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//ensure the ability system component is valid and bind it to input
	if (AbilitySystemComponent && PlayerInputComponent) {

		AbilitySystemComponent->BindAbilityActivationToInputComponent(PlayerInputComponent, FGameplayAbilityInputBinds(
			"Confirm",
			"Cancel",
			"EGASAbilityInputID",
			static_cast<int32>(EGASAbilityInputID::Confirm),
			static_cast<int32>(EGASAbilityInputID::Cancel)));

	}

}

