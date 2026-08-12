// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "CombatAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class GAS_NEXUS_API UCombatAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UCombatAttributeSet();
	
	// Armor Attributes
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Armor)
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS_BASIC(UCombatAttributeSet, Armor)
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxArmor)
	FGameplayAttributeData MaxArmor;
	ATTRIBUTE_ACCESSORS_BASIC(UCombatAttributeSet, MaxArmor)

	// Strength Attributes
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Strength)
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS_BASIC(UCombatAttributeSet, Strength)
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxStrength)
	FGameplayAttributeData MaxStrength;
	ATTRIBUTE_ACCESSORS_BASIC(UCombatAttributeSet, MaxStrength)
	
protected:
	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldData) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UCombatAttributeSet, Armor, OldData);
	}
	
	UFUNCTION()
	void OnRep_MaxArmor(const FGameplayAttributeData& OldData) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UCombatAttributeSet, MaxArmor, OldData);
	}
	
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldData) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UCombatAttributeSet, Strength, OldData);
	}
	
	UFUNCTION()
	void OnRep_MaxStrength(const FGameplayAttributeData& OldData) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UCombatAttributeSet, MaxStrength, OldData);
	}
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
