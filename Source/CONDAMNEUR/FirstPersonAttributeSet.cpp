// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonAttributeSet.h"

UFirstPersonAttributeSet::UFirstPersonAttributeSet() {

}

void UFirstPersonAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) {
	NewValue = FMath::Clamp<float>(NewValue, 0, 100);
}

bool UFirstPersonAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data) {
	float AbsoluteMagnitude = FMath::Abs(Data.EvaluatedData.Magnitude);

	if (Data.EvaluatedData.Magnitude > 0) {
		if (Data.EvaluatedData.Attribute == GetArmorAttribute() && GetArmor() + AbsoluteMagnitude >= 100) {
			SetArmor(100);
			return false;
		}

		if (Data.EvaluatedData.Attribute == GetHealthAttribute() && GetHealth() + AbsoluteMagnitude >= 100) {
			SetHealth(100);
			return false;
		}
	}
	else {
		if (Data.EvaluatedData.Attribute == GetArmorAttribute() && AbsoluteMagnitude > GetArmor())
			Health.SetCurrentValue(Health.GetCurrentValue() - (AbsoluteMagnitude - GetArmor()));
	}

	return true;
}