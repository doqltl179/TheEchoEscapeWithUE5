#include "GameInstance/Singleton.h"

void USingleton::Init() {
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("[Singleton] Init"));

	ScreenEffectManager = CreateSingletonObject<UScreenEffectManager>(this);
}