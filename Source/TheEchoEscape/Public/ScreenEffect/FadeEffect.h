#pragma once

#include "CoreMinimal.h"
#include "ScreenEffect/ScreenEffect.h"
#include "Components/Image.h"
#include "FadeEffect.generated.h"

UCLASS()
class THEECHOESCAPE_API UFadeEffect : public UScreenEffect {
	GENERATED_BODY()

private:
	UImage* FadeImage;

	float fadeFrom;
	float fadeTo;

	//const float effectTime = 0.8f;
	const float effectTime = 5.0f;
	float timer;

protected:
	virtual void InitParams() override;

	virtual void TickEvent(float DeltaTime) override;
	virtual bool StopCondition() override;

public:
	const void SetFromToValue(float InFrom, float InTo) {
		fadeFrom = InFrom;
		fadeTo = InTo;
	}

	const void SetFadeImage(UImage* InImage) {
		FadeImage = InImage;
	}
};
