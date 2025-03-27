#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "BaseballGameState.generated.h"


UCLASS()
class SVMULTI_API ABaseballGameState : public AGameState
{
	GENERATED_BODY()
	
public:
	ABaseballGameState();


	APlayerController* GetCurrentTurnPlayer() const { return CurrentTurnPlayer; }
	void SetCurrentTurnPlayer(APlayerController* NewTurnPlayer); //플레이어 컨트롤러 / 뉴턴플레이어 컨트롤러에서 아무나 뽑아서 순서 정하기

	float GetCurrentTurnTimeRemaining() { return CurrentTurnTimeRemaining; }
	void SetCurrentTurnTimeRemaining(float time) { this->CurrentTurnTimeRemaining = time; }

private:
	UPROPERTY(ReplicatedUsing = OnRep_CurrentTurnPlayer)
	APlayerController* CurrentTurnPlayer; //값이 변하면 OnRep_CurrentTurnPlayer이 함수가 호출이 된다.

	UFUNCTION()
	void OnRep_CurrentTurnPlayer();
	void OnCurrentTurnPlayerChanged(); //변수값이 변하면 호출되는 함수 

	// 현재 남은 턴 시간 (UI 표시용)
	UPROPERTY(Replicated) //값이 변경이되면 자동으로 알려줌
	float CurrentTurnTimeRemaining;

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};