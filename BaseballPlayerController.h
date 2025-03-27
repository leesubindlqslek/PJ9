#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BaseballPlayerController.generated.h"


UCLASS()
class SVMULTI_API ABaseballPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	void CreateWidgetOnViewport();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(Server, Reliable)
	void ServerSendReadyValue(bool IsReady); // �÷��̾� ��Ʈ�ѷ��� �ڽ� Ŭ���������� ������ �ǵ���

public:
	ABaseballPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD") //�÷��̾� ��Ʈ�ѷ� ������ ���� ī�װ� HUD�� ���. ���⿡ ���� ����
	TSubclassOf<UUserWidget> HUDWidgetClass; // ���� ���� ��������
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HUD")
	UUserWidget* HUDWidgetInstance; //���� �����ϰ� �ִ� ����Ʈ

	UFUNCTION(Client, Reliable) //Ŭ���̾�Ʈ rpc . / �տ� �������� �̸� ���ֱ�
	void ClientSetMyTurn();

	UFUNCTION(Client, Reliable)
	void ClientSetOtherTurn();

	UFUNCTION(Server, Reliable) //���� rpc
	void ServerSubmitGuess(const FString& InputNumber);

	UFUNCTION(Client, Reliable)
	void ClientReceiveResult(const FString& InputNumber, int32 Strike, int32 Ball);

	UFUNCTION(Client, Reliable)
	void ClientShowMessage(const FString& Message);

	UFUNCTION(Client, Reliable)
	void ClientUpdateTurnTime(float RemainingTime);

	UFUNCTION(Client, Reliable)
	void ClientOnGameWin();

	UFUNCTION(Client, Reliable)
	void ClientOnGameLose();

	UFUNCTION(Server, Reliable)
	void ServerRequestRestart();

	UFUNCTION(Client, Reliable)
	void ClientResettingbuttons();
};