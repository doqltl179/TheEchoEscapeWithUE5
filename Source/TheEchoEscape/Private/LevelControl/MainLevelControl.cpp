#include "LevelControl/MainLevelControl.h"
#include "Blueprint/UserWidget.h"

void AMainLevelControl::BeginPlay() {
    Super::BeginPlay();

    UE_LOG(LogTemp, Log, TEXT("[AMainLevelControl] BeginPlay"));

    if(!MainUIClass) {
        UE_LOG(LogTemp, Error, TEXT("[AMainLevelControl] MainUIClass not found."));
        return;
    }

    MainUIInstance = CreateWidget<UUserWidget>(GetWorld(), MainUIClass);
    if(MainUIInstance) {
        MainUIInstance->AddToViewport();
    }
}
