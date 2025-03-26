#include "MainGameMode.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"

void AMainGameMode::BeginPlay() {
	// �θ� Ŭ������ "BeginPlay" �Լ��� ȣ��
	Super::BeginPlay();

    if(MainUIClass) {
        MainUIInstance = CreateWidget<UUserWidget>(GetWorld(), MainUIClass);
        if(MainUIInstance) {
            MainUIInstance->AddToViewport();
        }
    }
}
