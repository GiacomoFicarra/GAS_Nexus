// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "NexusGameplayAbility.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EAbilityInputID : uint8
{
	None UMETA(DisplayName = "None"),
	PrimaryAbility UMETA(DisplayName = "Primary Ability"),
	SecondaryAbility UMETA(DisplayName = "Secondary Ability"),
	DefensiveAbility UMETA(DisplayName = "Defensive Ability"),
	MovementAbility UMETA(DisplayName = "Movement Ability"),
};

UCLASS()
class GAS_NEXUS_API UNexusGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:

	UNexusGameplayAbility();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "UI")
	bool ShouldShowInAbilitiesBar = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Activation")
	bool AutoActivateWhenGranted = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Input")
	EAbilityInputID AbilityInputID = EAbilityInputID::None;
	
	UFUNCTION(BlueprintCallable, Category = "Ability")
	void SetAbilityLevel(int32 NewLevel);
	
	private:
	UFUNCTION(BlueprintCallable, Category = "Helpers")
	bool HasPC() const;
};
