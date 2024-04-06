// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "FirstPersonAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName) \


/**
 * 
 */
UCLASS()
class CONDAMNEUR_API UFirstPersonAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UFirstPersonAttributeSet();

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UFirstPersonAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UFirstPersonAttributeSet, Armor);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Bullets;
	ATTRIBUTE_ACCESSORS(UFirstPersonAttributeSet, Bullets);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Plasma;
	ATTRIBUTE_ACCESSORS(UFirstPersonAttributeSet, Plasma);

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual bool PreGameplayEffectExecute(struct FGameplayEffectModCallbackData& Data) override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
};
