// Project Settings/Project/Maps & Modes �׸��� "Game Instance/Game Instance Class���� ����

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Singleton.generated.h"

UCLASS()
class THEECHOESCAPE_API USingleton : public UGameInstance {
	GENERATED_BODY()

protected:
	virtual void Init() override;

public:

};
