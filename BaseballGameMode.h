#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "BaseballPlayerController.h"
#include "BaseballGameMode.generated.h"

UCLASS()
class SVMULTI_API ABaseballGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ABaseballGameMode();

	static int32 GetDigitsCount() { return DIGITS_COUNT; }

	int ReadyCount = 0;

	int32 GetReadyCount() { return ReadyCount; } //2��

	int32 GetMaxPlayer() { return MaxPlayer; }

	void CheckAnswer(ABaseballPlayerController* PlayerController, const FString& InputNumberString);

	void RequestRestartGame(APlayerController* RequestingPC);

	void Ready();

	void StartGame();

protected:
	virtual void BeginPlay() override;

	virtual void PostLogin(APlayerController* NewPlayer) override;

	FString GenerateRandomNumber(const int32 DigitCount);

	void PickRandomFirstTurnPlayer();

	void NextTurn();

private:
	int32 MaxPlayer = 0; //�÷��̾� ����

	static const int32 DIGITS_COUNT = 3; //���� ���� ��
	
	FString ServerNumber; 

	UPROPERTY()
	float TurnTimeLimit = 10.0f; // 10�� �Ŀ� ���� �Ѿ 

	TArray<ABaseballPlayerController*> PlayerControllers;

	FTimerHandle TurnTimerHandle;

	// �ð� ������Ʈ Ÿ�̸� ����
	FTimerHandle UpdateTimerHandle;

	// �� Ÿ�̸� ���� �Լ�
	void StartTurnTimer();

	// �� Ÿ�Ӿƿ� ó�� �Լ�
	void HandleTurnTimeout();

	// �� �ð� ������Ʈ �Լ�
	void UpdateTurnTimeRemaining();
};