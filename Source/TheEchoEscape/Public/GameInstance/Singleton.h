// Project Settings/Project/Maps & Modes �׸��� "Game Instance/Game Instance Class���� ����

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "ScreenEffectManager.h"

#include "Singleton.generated.h"

UCLASS()
class THEECHOESCAPE_API USingleton : public UGameInstance {
	GENERATED_BODY()

protected:
	// template�� ���� �Լ��� �ݵ�� .h���� �����ؾ� �Ѵ�.
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
