// Project Settings/Project/Maps & Modes 항목중 "Game Instance/Game Instance Class에서 설정

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "ScreenEffectManager.h"

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
			FString className = Outer->GetName();
			UE_LOG(LogTemp, Error, TEXT("[USingleton] Class not found. name: %s"), *className);
		}

		return Cast<T>(instanceObject);
	}

	virtual void Init() override;

	UPROPERTY()
	UScreenEffectManager* ScreenEffectManager;

public:
	UScreenEffectManager* GetScreenEffectManager() const { return ScreenEffectManager; }
};
