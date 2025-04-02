#include "ScreenEffectManager.h"

void UScreenEffectManager::CreateUIEffect() {
	FString Path = TEXT("/Game/Blueprints/BP_UIEffect.BP_UIEffect_C"); // 경로 뒤에 '_C'를 수동으로 붙여줘야 한다.
	FStringClassReference WidgetClassRef(Path);
	UClass* WidgetClass = WidgetClassRef.TryLoadClass<UUserWidget>();
	if(!WidgetClass) {
		UE_LOG(LogTemp, Error, TEXT("[UScreenEffectManager] WidgetClass not found."));
		return;
	}

	UWorld* World = GetWorld();
	if(!World) {
		UE_LOG(LogTemp, Error, TEXT("[UScreenEffectManager] World not found."));
		return;
	}

	UIEffectInstance = CreateWidget<UUIEffect>(World, WidgetClass);
	if(UIEffectInstance) {
		UIEffectInstance->AddToViewport(5000); // ZOrder를 5000으로 설정

		UIEffectInstance->OnStart();
	}
}

void UScreenEffectManager::CreatePostProcessVolume() {
	if(PostProcessVolume) {
		return;
	}

	UWorld* World = GetWorld();
	if(!World) {
		UE_LOG(LogTemp, Error, TEXT("[UScreenEffectManager] World not found."));
		return;
	}

	FActorSpawnParameters SpawnParams;
	SpawnParams.Name = FName(TEXT("GlobalPostEffect"));
	SpawnParams.OverrideLevel = World->PersistentLevel;
	// 스폰 시 충돌 상황에서 어떻게 처리할 것인지 지정
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	PostProcessVolume = World->SpawnActor<APostProcessVolume>(
		APostProcessVolume::StaticClass(), FVector(0, 0, 0), FRotator::ZeroRotator, SpawnParams
	);
	if(!PostProcessVolume) {
		UE_LOG(LogTemp, Error, TEXT("[UScreenEffectManager] Failed create PostProcessVolume."));
		return;
	}
#if WITH_EDITOR
	else {
		PostProcessVolume->SetActorLabel(TEXT("RunTimeInstance_GlobalPostEffect"));
	}
#endif

	PostProcessVolume->bUnbound = true;
	if(EffectMaterial) {
		FWeightedBlendable Blendable;
		Blendable.Object = EffectMaterial;
		Blendable.Weight = 1.0f;

		PostProcessVolume->Settings.WeightedBlendables.Array.Add(Blendable);
	}
}

void UScreenEffectManager::FindEffectMaterial() {
	if(EffectMaterial) {
		return;
	}

	FString Path = TEXT("/Game/Materials/M_GlobalScreenEffect.M_GlobalScreenEffect");
	UMaterialInstance* MaterialInstance = Cast<UMaterialInstance>(
		StaticLoadObject(UMaterialInterface::StaticClass(), this, *Path));

	if(!MaterialInstance) {
		// 위에서 찾은 머티리얼을 동적 머티리얼로 생성
		EffectMaterial = UMaterialInstanceDynamic::Create(MaterialInstance, this, FName("EffectMaterial"));
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
}

void UScreenEffectManager::OnStart() {
	UE_LOG(LogTemp, Log, TEXT("[UScreenEffectManager] OnStart"));

	CreatePostProcessVolume();
	CreateUIEffect();
}
