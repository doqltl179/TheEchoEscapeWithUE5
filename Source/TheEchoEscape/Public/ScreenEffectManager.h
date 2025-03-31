#pragma once

#include "CoreMinimal.h"
#include "GameInstance/SingletonObject.h"
#include "GameInstance/TickObject.h"
#include "ScreenEffectManager.generated.h"

UCLASS()
class THEECHOESCAPE_API UScreenEffectManager : public USingletonObject, public FTickObject {
	GENERATED_BODY()

private:
	const FName MatParamName_FadeStrength = TEXT("FadeStrength");

	void CreatePostProcessVolume();
	void FindEffectMaterial();

protected:
	UPROPERTY()
	APostProcessVolume* PostProcessVolume;

	UPROPERTY()
	UMaterialInstanceDynamic* EffectMaterial;

public:
	virtual void Init() override;
	virtual void OnStart() override;
};
