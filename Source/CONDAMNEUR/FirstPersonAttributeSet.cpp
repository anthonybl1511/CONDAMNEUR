// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstPersonAttributeSet.h"
#include "FirstPersonCharacter.h"

UFirstPersonAttributeSet::UFirstPersonAttributeSet() {

}

void UFirstPersonAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) {
	AFirstPersonCharacter* FPChar = Cast<AFirstPersonCharacter>(GetOwningActor());
	
	if(Attribute == GetHealthAttribute())
		NewValue = FMath::Clamp<float>(NewValue, 0, FPChar->MaxHealth);
	else if (Attribute == GetArmorAttribute())
		NewValue = FMath::Clamp<float>(NewValue, 0, FPChar->MaxArmor);
	else if (Attribute == GetBulletsAttribute())
		NewValue = FMath::Clamp<float>(NewValue, 0, FPChar->MaxBullets);
	else if (Attribute == GetPlasmaAttribute())
		NewValue = FMath::Clamp<float>(NewValue, 0, FPChar->MaxPlasma);
	
}

bool UFirstPersonAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data) {
	float AbsoluteMagnitude = FMath::Abs(Data.EvaluatedData.Magnitude);

	AFirstPersonCharacter* FPChar = Cast<AFirstPersonCharacter>(GetOwningActor());

	if (Data.EvaluatedData.Magnitude > 0) {
		if (Data.EvaluatedData.Attribute == GetArmorAttribute() && GetArmor() + AbsoluteMagnitude >= FPChar->MaxArmor) {
			SetArmor(FPChar->MaxArmor);
			return false;
		}
		else if (Data.EvaluatedData.Attribute == GetHealthAttribute() && GetHealth() + AbsoluteMagnitude >= FPChar->MaxHealth) {
			SetHealth(FPChar->MaxHealth);
			return false;
		}
		else if (Data.EvaluatedData.Attribute == GetBulletsAttribute() && GetBullets() + AbsoluteMagnitude >= FPChar->MaxBullets) {
			SetBullets(FPChar->MaxBullets);
			return false;
		}
		else if (Data.EvaluatedData.Attribute == GetPlasmaAttribute() && GetPlasma() + AbsoluteMagnitude >= FPChar->MaxPlasma) {
			SetPlasma(FPChar->MaxPlasma);
			return false;
		}
	}
	else if (Data.EvaluatedData.Magnitude < 0) {
		if (Data.EvaluatedData.Attribute == GetArmorAttribute() && AbsoluteMagnitude > GetArmor())
			Health.SetCurrentValue(Health.GetCurrentValue() - (AbsoluteMagnitude - GetArmor()));
	}

	return true;
}

void UFirstPersonAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute == GetHealthAttribute() && GetHealth() < 0)
		SetHealth(0);
	else if (Data.EvaluatedData.Attribute == GetArmorAttribute() && GetArmor() < 0)
		SetArmor(0);
	else if (Data.EvaluatedData.Attribute == GetBulletsAttribute() && GetBullets() < 0)
		SetBullets(0);
	else if (Data.EvaluatedData.Attribute == GetPlasmaAttribute() && GetPlasma() < 0)
		SetPlasma(0);
}
