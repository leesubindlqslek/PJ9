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
	void SetCurrentTurnPlayer(APlayerController* NewTurnPlayer); //�÷��̾� ��Ʈ�ѷ� / �����÷��̾� ��Ʈ�ѷ����� �ƹ��� �̾Ƽ� ���� ���ϱ�

	float GetCurrentTurnTimeRemaining() { return CurrentTurnTimeRemaining; }
	void SetCurrentTurnTimeRemaining(float time) { this->CurrentTurnTimeRemaining = time; }

private:
	UPROPERTY(ReplicatedUsing = OnRep_CurrentTurnPlayer)
	APlayerController* CurrentTurnPlayer; //���� ���ϸ� OnRep_CurrentTurnPlayer�� �Լ��� ȣ���� �ȴ�.

	UFUNCTION()
	void OnRep_CurrentTurnPlayer();
	void OnCurrentTurnPlayerChanged(); //�������� ���ϸ� ȣ��Ǵ� �Լ� 

	// ���� ���� �� �ð� (UI ǥ�ÿ�)
	UPROPERTY(Replicated) //���� �����̵Ǹ� �ڵ����� �˷���
	float CurrentTurnTimeRemaining;

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};