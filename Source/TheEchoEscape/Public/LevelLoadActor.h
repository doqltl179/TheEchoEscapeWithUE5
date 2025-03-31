#pragma once

#include "CoreMinimal.h"
#include "GameInstance/SingletonActor.h"
#include "LevelLoadActor.generated.h"

UCLASS()
class THEECHOESCAPE_API ALevelLoadActor : public ASingletonActor {
	GENERATED_BODY()

public:
	ALevelLoadActor();

	void LoadMainLevel() { LoadLevel(LevelName_Main); }
	void LoadGameLevel() { LoadLevel(LevelName_Game); }

	void UnloadMainLevel() { LoadLevel(LevelName_Main); }
	void UnloadGameLevel() { LoadLevel(LevelName_Game); }

protected:
	virtual void BeginPlay() override;

private:
	const FName LevelName_Main = FName(TEXT("Main"));
	const FName LevelName_Game = FName(TEXT("Game"));

	void LoadLevel(FName LevelName);
	void UnloadLevel(FName LevelName);
};
