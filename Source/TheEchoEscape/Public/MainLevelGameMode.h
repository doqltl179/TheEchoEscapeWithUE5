#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainLevelGameMode.generated.h"

UCLASS()
class THEECHOESCAPE_API AMainLevelGameMode : public AGameModeBase {
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> MainUIClass; // "BP_MainLevelGameMode"의 Details 패널에서 설정함

	UPROPERTY()
	UUserWidget* MainUIInstance;
};
