#include "GameInstance/Singleton.h"

void USingleton::Init() {
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("[USingleton] Init"));

	ScreenEffectManager = CreateSingletonObject<UScreenEffectManager>(this);
}

void USingleton::OnStart() {
	Super::OnStart();

	UE_LOG(LogTemp, Log, TEXT("[USingleton] OnStart"));

	if(ScreenEffectManager) {
		ScreenEffectManager->OnStart();
	}

	UWorld* World = GetWorld();
	if(World) {
		LevelLoadActor = CreateSingletonActor<ALevelLoader>(World);
	}
}
