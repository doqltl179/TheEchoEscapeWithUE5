#pragma once

#include "CoreMinimal.h"
#include "LevelControl/LevelControl.h"
#include "MainLevelControl.generated.h"

UCLASS()
class THEECHOESCAPE_API AMainLevelControl : public ALevelControl {
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "UI", meta = (BlueprintBaseOnly))
	TSubclassOf<class UMainUI> MainUIClass; // Details 패널에서 설정함

	UPROPERTY()
	UMainUI* MainUIInstance;

public:
	virtual void BeginPlay() override;


};
