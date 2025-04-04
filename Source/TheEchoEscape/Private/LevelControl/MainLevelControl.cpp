#include "LevelControl/MainLevelControl.h"
#include "BlueprintParent/MainUI.h"

void AMainLevelControl::BeginPlay() {
    Super::BeginPlay();

    UE_LOG(LogTemp, Log, TEXT("[AMainLevelControl] BeginPlay"));

    if(!MainUIClass) {
        UE_LOG(LogTemp, Error, TEXT("[AMainLevelControl] MainUIClass not found."));
        return;
    }
    else if(MainUIClass->ClassGeneratedBy == nullptr) {
        UE_LOG(LogTemp, Error, TEXT("[AMainLevelControl] MainUIClass is not a Blueprint."));
        return;
    }

    MainUIInstance = CreateWidget<UMainUI>(GetWorld(), MainUIClass);
    if(MainUIInstance) {
        MainUIInstance->AddToViewport();
    }
}
