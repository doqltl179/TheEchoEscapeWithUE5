#include "LevelLoadActor.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/LevelStreamingDynamic.h"

ALevelLoadActor::ALevelLoadActor() {
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	SetActorTickEnabled(false);
}

void ALevelLoadActor::BeginPlay() {
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("[ALevelLoadActor] BeginPlay"));

	LoadMainLevel();
}

void ALevelLoadActor::LoadLevel(FName LevelName) {
	UGameplayStatics::LoadStreamLevel(this, LevelName, true, false, FLatentActionInfo());
}

void ALevelLoadActor::UnloadLevel(FName LevelName) {
	UGameplayStatics::UnloadStreamLevel(this, LevelName, FLatentActionInfo(), false);
}

