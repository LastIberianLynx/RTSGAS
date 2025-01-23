// Fill out your copyright notice in the Description page of Project Settings.


#include "MyChangeColorAbility.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "RTSPawn.h"
#include "UnitManager.h"


void UMyChangeColorAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{

	//Check if the actor has a valid reference
	if (ARTSPawn* RTSPawn = Cast<ARTSPawn>(ActorInfo->AvatarActor.Get())) {
		//Make unit change color
		int32 unitIndexTest = 0;
		FColor ColorTest = FColor::Red;
		RTSPawn->UnitManager->ChangeColor(unitIndexTest, ColorTest);
	}
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);

}
