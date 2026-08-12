// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicAttributeSet.h"

#include "Net/UnrealNetwork.h"

UMagicAttributeSet::UMagicAttributeSet()
{
	Mana = 100.0f;
	MaxMana = 100.0f;
}

void UMagicAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UMagicAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMagicAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}
