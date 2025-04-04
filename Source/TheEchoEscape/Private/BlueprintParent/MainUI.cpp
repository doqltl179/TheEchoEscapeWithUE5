#include "BlueprintParent/MainUI.h"

void UMainUI::OnClickStartButton() {
	UE_LOG(LogTemp, Log, TEXT("[UMainUI] OnClickStartButton"));
}

void UMainUI::OnClickSettingsButton() {
	UE_LOG(LogTemp, Log, TEXT("[UMainUI] OnClickSettingsButton"));
}

void UMainUI::OnClickExitButton() {
	UE_LOG(LogTemp, Log, TEXT("[UMainUI] OnClickExitButton"));
}
