#include "LevelLoader.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/LevelStreamingDynamic.h"

ALevelLoader::ALevelLoader() {
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	SetActorTickEnabled(false);
}

void ALevelLoader::BeginPlay() {
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("[ALevelLoader] BeginPlay"));

	LoadMainLevel();
}

void ALevelLoader::LoadLevel(FName LevelName) {
	UGameplayStatics::LoadStreamLevel(this, LevelName, true, false, FLatentActionInfo());
}

void ALevelLoader::UnloadLevel(FName LevelName) {
	UGameplayStatics::UnloadStreamLevel(this, LevelName, FLatentActionInfo(), false);
}

