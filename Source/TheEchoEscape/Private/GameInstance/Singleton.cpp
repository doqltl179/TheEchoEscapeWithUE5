#include "GameInstance/Singleton.h"
//#include "Kismet/GameplayStatics.h"

void USingleton::Init() {
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("[Singleton] Init"));

	ScreenEffectManager = CreateSingletonObject<UScreenEffectManager>(this);



	//UGameplayStatics::LoadStreamLevel(
	//	this,
	//	FName("Main"),  // 서브레벨 이름
	//	true,           // make visible
	//	false,          // should block
	//	FLatentActionInfo()
	//);
}

void USingleton::OnStart() {
	if(ScreenEffectManager) {
		ScreenEffectManager->OnStart();
	}
}
