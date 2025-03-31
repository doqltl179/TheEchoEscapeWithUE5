#include "MainLevelGameMode.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"

void AMainLevelGameMode::BeginPlay() {
	Super::BeginPlay();

    UE_LOG(LogTemp, Log, TEXT("[AMainLevelGameMode] BeginPlay"));

    if(MainUIClass) {
        MainUIInstance = CreateWidget<UUserWidget>(GetWorld(), MainUIClass);
        if(MainUIInstance) {
            MainUIInstance->AddToViewport();
        }
    }
}
