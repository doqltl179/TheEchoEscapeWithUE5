#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"

#include "ScreenEffect/FadeEffect.h"

#include "UIEffect.generated.h"

UCLASS()
class THEECHOESCAPE_API UUIEffect : public UUserWidget {
	GENERATED_BODY()

private:
	template<typename T, typename = TEnableIf<TIsDerivedFrom<T, UScreenEffect>::IsDerived>::Type>
	T* CreateObject(UObject* Outer) {
		UScreenEffect* instanceObject = NewObject<UScreenEffect>(this);

		if(instanceObject) {
			
		}
		else {
			FString ObjectName = FString(T::StaticClass()->GetName());
			UE_LOG(LogTemp, Error, TEXT("[USingleton] Class not found. name: %s"), *ObjectName);
		}

		return Cast<T>(instanceObject);
	}

	UPROPERTY()
	UFadeEffect* FadeEffect;

protected:
	UPROPERTY(meta = (BindWidget), EditAnywhere, Category = "UI")
	UImage* FadeImage;

public:
	virtual void OnStart();
};
