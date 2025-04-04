#include "LevelControl/GameLevelControl.h"
#include "BlueprintParent/GameMenuUI.h"

void AGameLevelControl::BeginPlay() {
    Super::BeginPlay();

    UE_LOG(LogTemp, Log, TEXT("[AGameLevelControl] BeginPlay"));

    if(!MenuUIClass) {
        UE_LOG(LogTemp, Error, TEXT("[AGameLevelControl] MainUIClass not found."));
        return;
    }
    else if(MenuUIClass->ClassGeneratedBy == nullptr) {
        UE_LOG(LogTemp, Error, TEXT("[AGameLevelControl] MainUIClass is not a Blueprint."));
        return;
    }

    MenuUIInstance = CreateWidget<UGameMenuUI>(GetWorld(), MenuUIClass);
    if(MenuUIInstance) {
        MenuUIInstance->AddToViewport();
        MenuUIInstance->SetVisibility(ESlateVisibility::Hidden);
    }
}
