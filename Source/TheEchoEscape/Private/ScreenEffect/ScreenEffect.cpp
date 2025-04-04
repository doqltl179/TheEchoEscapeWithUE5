#include "ScreenEffect/ScreenEffect.h"

void UScreenEffect::InitParams() { }

void UScreenEffect::TickEvent(float DeltaTime) { }

bool UScreenEffect::StopCondition() { return true; }

void UScreenEffect::Execute(TFunction<void()> InTickEnd) {
	InitParams();

	StartTick(
		[this](float DeltaTime) { this->TickEvent(DeltaTime); },
		[this]() { return this->StopCondition(); },
		InTickEnd);
}
