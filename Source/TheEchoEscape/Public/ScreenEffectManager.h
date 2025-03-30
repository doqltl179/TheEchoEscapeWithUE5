// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameInstance/SingletonObject.h"
#include "GameInstance/TickObject.h"
#include "ScreenEffectManager.generated.h"

UCLASS()
class THEECHOESCAPE_API UScreenEffectManager : public USingletonObject, public FTickObject {
	GENERATED_BODY()

private:
	void FindEffectMaterial();

protected:
	UPROPERTY()
	UMaterialInstanceDynamic* EffectMaterial;

public:
	virtual void Init() override;
};
