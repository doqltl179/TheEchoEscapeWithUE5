#include "ScreenEffect/FadeEffect.h"

void UFadeEffect::InitParams() {
	timer = 0.0f;
}

void UFadeEffect::TickEvent(float DeltaTime) {
	timer += DeltaTime;

	float opacity = FMath::Lerp(fadeFrom, fadeTo, timer / effectTime);
	FadeImage->SetOpacity(FMath::Clamp(opacity, 0.0, 1.0));
}

bool UFadeEffect::StopCondition() {
	return timer >= effectTime;
}
