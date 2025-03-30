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

	// �Ͻ����� �߿��� Tick���� ����
	virtual bool IsTickableWhenPaused() const override { return false; }

	// Unreal ������ ��� �ý��ۿ� �ʿ��� �׸�
	virtual TStatId GetStatId() const override {
		// (UMyTickable, STATGROUP_Tickables)
		// UMyTickable: ��� �̸� (Ŭ���� �̸��� ���� ���� ���� ����)
		// STATGROUP_Tickables: ���� �׷� �̸�
		RETURN_QUICK_DECLARE_CYCLE_STAT(FTickObject, STATGROUP_Tickables);
	}

	void StartTick(TFunction<void(float)> InTickEvent, TFunction<bool()> InStopCondition, TFunction<void()> InTickEnd);
};
