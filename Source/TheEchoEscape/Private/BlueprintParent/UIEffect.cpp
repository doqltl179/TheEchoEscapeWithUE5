#include "BlueprintParent/UIEffect.h"

void UUIEffect::OnStart() {
	UE_LOG(LogTemp, Log, TEXT("[UUIEffect] OnStart"));

	FadeEffect = NewObject<UFadeEffect>(this, UFadeEffect::StaticClass());
    if(FadeEffect) {
		FadeEffect->SetFadeImage(FadeImage);



		// Test
		FadeEffect->SetFromToValue(0.0f, 1.0f);
		FadeEffect->Execute(
			[this]() {
				UE_LOG(LogTemp, Log, TEXT("[UUIEffect] Fade End"));
			}
		);
    }
}
