// Fill out your copyright notice in the Description page of Project Settings.


#include "MyChangeColorAbility.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "RTSPawn.h"
#include "UnitManager.h"

void UMyChangeColorAbility::SetChangeColorParams(int32 InUnitIndex, FColor InColor)
{
	UnitIndex = InUnitIndex;
	Color = InColor;
}

void UMyChangeColorAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{

	//Check if the actor has a valid reference
	if (ARTSPawn* RTSPawn = Cast<ARTSPawn>(ActorInfo->AvatarActor.Get())) {
		//Make unit change color
		RTSPawn->UnitManager->ChangeColor(UnitIndex, Color);
	}
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);

}
