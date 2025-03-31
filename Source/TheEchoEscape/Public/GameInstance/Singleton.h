#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "ScreenEffectManager.h"
#include "LevelLoadActor.h"

#include "Singleton.generated.h"

UCLASS()
class THEECHOESCAPE_API USingleton : public UGameInstance {
	GENERATED_BODY()

protected:
	// template이 붙은 함수는 반드시 .h에서 구현해야 한다.
	template<typename T, typename = TEnableIf<TIsDerivedFrom<T, USingletonObject>::IsDerived>::Type>
	T* CreateSingletonObject(UObject* Outer) {
		USingletonObject* instanceObject = NewObject<T>(Outer);

		if(instanceObject) {
			instanceObject->Init();
		}
		else {
			FString ObjectName = FString(T::StaticClass()->GetName());
			UE_LOG(LogTemp, Error, TEXT("[USingleton] Class not found. name: %s"), *ObjectName);
		}

		return Cast<T>(instanceObject);
	}

	template<typename T, typename = TEnableIf<TIsDerivedFrom<T, ASingletonActor>::IsDerived>::Type>
	T* CreateSingletonActor(UWorld* World) {
		FActorSpawnParameters SpawnParams;
		FString ActorName = FString(T::StaticClass()->GetName());
		SpawnParams.Name = *ActorName;
		SpawnParams.OverrideLevel = World->PersistentLevel;
		ASingletonActor* instanceActor = World->SpawnActor<ASingletonActor>(ALevelLoadActor::StaticClass(), SpawnParams);

		if(instanceActor) {
#if WITH_EDITOR
			instanceActor->SetActorLabel(TEXT("RunTimeInstance_") + ActorName);
#endif
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("[USingleton] Class not found. name: %s"), *ActorName);
		}

		return Cast<T>(instanceActor);
	}

	virtual void Init() override;
	virtual void OnStart() override;

	UPROPERTY()
	UScreenEffectManager* ScreenEffectManager;

	UPROPERTY()
	ALevelLoadActor* LevelLoadActor;

public:
	UScreenEffectManager* GetScreenEffectManager() const { return ScreenEffectManager; }
};
