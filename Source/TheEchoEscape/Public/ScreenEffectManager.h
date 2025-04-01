#pragma once

#include "CoreMinimal.h"
#include "GameInstance/SingletonObject.h"
#include "GameInstance/TickObject.h"
#include "BlueprintParent/UIEffect.h"
#include "ScreenEffectManager.generated.h"

UCLASS()
class THEECHOESCAPE_API UScreenEffectManager : public USingletonObject, public FTickObject {
	GENERATED_BODY()

private:
	const FName MatParamName_FadeStrength = TEXT("FadeStrength");

	void FindEffectMaterial();
	void CreatePostProcessVolume();
	void CreateUIEffect();

protected:
	UPROPERTY()
	APostProcessVolume* PostProcessVolume;

	UPROPERTY()
	UMaterialInstanceDynamic* EffectMaterial;

	UPROPERTY()
	UUIEffect* UIEffectInstance;

public:
	virtual void Init() override;
	virtual void OnStart() override;
};
