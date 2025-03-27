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

	int32 GetReadyCount() { return ReadyCount; } //2명

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
	int32 MaxPlayer = 0; //플레이어 제한

	static const int32 DIGITS_COUNT = 3; //받을 숫자 수
	
	FString ServerNumber; 

	UPROPERTY()
	float TurnTimeLimit = 10.0f; // 10초 후에 턴이 넘어감 

	TArray<ABaseballPlayerController*> PlayerControllers;

	FTimerHandle TurnTimerHandle;

	// 시간 업데이트 타이머 설정
	FTimerHandle UpdateTimerHandle;

	// 턴 타이머 시작 함수
	void StartTurnTimer();

	// 턴 타임아웃 처리 함수
	void HandleTurnTimeout();

	// 턴 시간 업데이트 함수
	void UpdateTurnTimeRemaining();
};