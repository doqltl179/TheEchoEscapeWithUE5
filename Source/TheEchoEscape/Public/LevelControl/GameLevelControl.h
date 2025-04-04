#pragma once

#include "CoreMinimal.h"
#include "LevelControl/LevelControl.h"
#include "GameLevelControl.generated.h"

UCLASS()
class THEECHOESCAPE_API AGameLevelControl : public ALevelControl {
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<class UGameMenuUI> MenuUIClass; // Details 패널에서 설정함

	UPROPERTY()
	UGameMenuUI* MenuUIInstance;

public:
	virtual void BeginPlay() override;


};
