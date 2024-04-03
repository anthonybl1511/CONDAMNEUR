// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include <GameplayEffectTypes.h>
#include "AbilitySystemInterface.h"
#include "FirstPersonCharacter.generated.h"

UCLASS()
class CONDAMNEUR_API AFirstPersonCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
		class UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
		class UFirstPersonAttributeSet* Attributes;

public:
	// Sets default values for this character's properties
	AFirstPersonCharacter();

	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "FirstPerson")
		TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "FirstPerson")
		TArray<TSubclassOf<class UGameplayAbility>> DefaultAbilities;
};
