#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameInstance/TickObject.h"
#include "Components/Image.h"
#include "UIEffect.generated.h"

UCLASS()
class THEECHOESCAPE_API UUIEffect : public UUserWidget, public FTickObject {
	GENERATED_BODY()

private:
	

protected:
	UPROPERTY(meta = (BindWidget), EditAnywhere, Category = "UI")
	UImage* FadeImage;

public:
	
};
