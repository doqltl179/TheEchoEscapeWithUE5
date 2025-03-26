// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SingletonObject.h"
#include "ScreenEffectManager.generated.h"

UCLASS()
class THEECHOESCAPE_API UScreenEffectManager : public USingletonObject {
	GENERATED_BODY()

public:
	virtual void Init() override;
};
