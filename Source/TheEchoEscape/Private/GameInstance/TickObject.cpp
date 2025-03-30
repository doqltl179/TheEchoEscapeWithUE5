#include "GameInstance/TickObject.h"

void FTickObject::Tick(float DeltaTime) {
	if(!IsTicking) {
		return;
	}

	if(TickEvent) {
		TickEvent(DeltaTime);
	}

	if(StopCondition && StopCondition()) {
		IsTicking = false;

		if(TickEnd) {
			TickEnd();
		}

		TickEvent = nullptr;
		StopCondition = nullptr;
		TickEnd = nullptr;
	}
}

void FTickObject::StartTick(TFunction<void(float)> InTickEvent, TFunction<bool()> InStopCondition, TFunction<void()> InTickEnd) {
	TickEvent = InTickEvent;
	StopCondition = InStopCondition;
	TickEnd = InTickEnd;

	IsTicking = true;
}
