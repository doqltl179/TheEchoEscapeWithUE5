#include "MainGameMode.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"

void AMainGameMode::BeginPlay() {
	// 부모 클래스의 "BeginPlay" 함수를 호출
	Super::BeginPlay();

    if(MainUIClass) {
        MainUIInstance = CreateWidget<UUserWidget>(GetWorld(), MainUIClass);
        if(MainUIInstance) {
            MainUIInstance->AddToViewport();
        }
    }
}
