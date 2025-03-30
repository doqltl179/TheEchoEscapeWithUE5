#pragma once

#include "CoreMinimal.h"

class THEECHOESCAPE_API FTickObject : public FTickableGameObject {
private:
	TFunction<void(float)> TickEvent;
	TFunction<bool()> StopCondition;
	TFunction<void()> TickEnd;

protected:
	bool IsTicking = false;

	virtual void Tick(float DeltaTime) override;

	virtual bool IsTickable() const override { return IsTicking; }

	// 일시정지 중에도 Tick할지 여부
	virtual bool IsTickableWhenPaused() const override { return false; }

	// Unreal 엔진의 통계 시스템에 필요한 항목
	virtual TStatId GetStatId() const override {
		// (UMyTickable, STATGROUP_Tickables)
		// UMyTickable: 통계 이름 (클래스 이름과 같게 짓는 것이 관례)
		// STATGROUP_Tickables: 성능 그룹 이름
		RETURN_QUICK_DECLARE_CYCLE_STAT(FTickObject, STATGROUP_Tickables);
	}

	void StartTick(TFunction<void(float)> InTickEvent, TFunction<bool()> InStopCondition, TFunction<void()> InTickEnd);
};
