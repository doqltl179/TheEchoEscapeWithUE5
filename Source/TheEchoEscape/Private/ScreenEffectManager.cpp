#include "ScreenEffectManager.h"

void UScreenEffectManager::FindEffectMaterial() {
	if(EffectMaterial) {
		return;
	}

	FString Path = TEXT("/Game/Materials/M_GlobalScreenEffect.M_GlobalScreenEffect");
	UMaterialInstance* MaterialInstance = Cast<UMaterialInstance>(
		StaticLoadObject(UMaterialInterface::StaticClass(), this, *Path));

	if(!MaterialInstance) {
		// 위에서 찾은 머티리얼을 동적 머티리얼로 생성
		EffectMaterial = UMaterialInstanceDynamic::Create(MaterialInstance, this);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("[UScreenEffectManager] Material not found. path: %s"), *Path);
	}
}

#pragma region Test Tick Func
float test = 0;
void TestTickEvent(float DeltaTime) {
	test += DeltaTime;

	UE_LOG(LogTemp, Log, TEXT("[UScreenEffectManager] TickEvent. time: %f"), test);
}
bool TestStopCondition() {
	if(test > 1.1) {
		UE_LOG(LogTemp, Log, TEXT("[UScreenEffectManager] StopCondition."));

		return true;
	}

	return false;
}
void TestTickEnd() {
	UE_LOG(LogTemp, Log, TEXT("[UScreenEffectManager] TickEnd."));
}
#pragma endregion

void UScreenEffectManager::Init() {
	UE_LOG(LogTemp, Log, TEXT("[UScreenEffectManager] Init"));

	FindEffectMaterial();

	StartTick(TestTickEvent, TestStopCondition, TestTickEnd);
}
