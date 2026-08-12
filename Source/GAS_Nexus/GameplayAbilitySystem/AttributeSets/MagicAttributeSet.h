// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "MagicAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class GAS_NEXUS_API UMagicAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UMagicAttributeSet();
	
	// Mana Attributes
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing= OnRep_Mana)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS_BASIC(UMagicAttributeSet, Mana);
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing= OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS_BASIC(UMagicAttributeSet, MaxMana);
	
public:
	
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldData) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UMagicAttributeSet, Mana, OldData);
	}
	
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldData) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UMagicAttributeSet, MaxMana, OldData);
	}
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
