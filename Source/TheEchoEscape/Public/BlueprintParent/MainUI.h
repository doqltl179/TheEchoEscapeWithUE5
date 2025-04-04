#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainUI.generated.h"

UCLASS()
class THEECHOESCAPE_API UMainUI : public UUserWidget {
	GENERATED_BODY()

public:
#pragma region UI Func
	UFUNCTION(BlueprintCallable)
	void OnClickStartButton();

	UFUNCTION(BlueprintCallable)
	void OnClickSettingsButton();

	UFUNCTION(BlueprintCallable)
	void OnClickExitButton();
#pragma endregion
};
