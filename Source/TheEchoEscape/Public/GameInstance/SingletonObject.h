#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SingletonObject.generated.h"

UCLASS()
class THEECHOESCAPE_API USingletonObject : public UObject {
	GENERATED_BODY()

public:
	virtual void Init();
	virtual void OnStart();
};
