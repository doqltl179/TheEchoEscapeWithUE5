#include "BlueprintParent/UIEffect.h"

void UUIEffect::OnStart() {
	UE_LOG(LogTemp, Log, TEXT("[UUIEffect] OnStart"));

	FadeEffect = NewObject<UFadeEffect>(this, UFadeEffect::StaticClass());
    if(FadeEffect) {
		if(FadeImage == nullptr) {
			UE_LOG(LogTemp, Error, TEXT("[UUIEffect] FadeImage is NULL."));
			return;
		}

		FadeEffect->SetFadeImage(FadeImage);

		FadeEffect->SetFromToValue(1.0f, 0.0f);
		FadeEffect->Execute(
			[this]() {
				UE_LOG(LogTemp, Log, TEXT("[UUIEffect] Fade End"));
			}
		);
    }
}
