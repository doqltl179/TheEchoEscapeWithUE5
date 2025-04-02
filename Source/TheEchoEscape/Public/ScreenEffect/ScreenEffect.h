#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TickObject.h"
#include "ScreenEffect.generated.h"

UCLASS()
class THEECHOESCAPE_API UScreenEffect : public UObject, public FTickObject {
	GENERATED_BODY()

protected:
	virtual void InitParams();

	virtual void TickEvent(float DeltaTime);
	virtual bool StopCondition();

public:
	const void Execute(TFunction<void()> InTickEnd) {
		InitParams();

		StartTick(
			[this](float DeltaTime) { this->TickEvent(DeltaTime); },
			[this]() { return this->StopCondition(); },
			InTickEnd);
	}
};
