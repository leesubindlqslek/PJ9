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
	void ServerSendReadyValue(bool IsReady); // 플레이어 컨트롤러나 자식 클래스에서만 실행이 되도록

public:
	ABaseballPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD") //플레이어 컨트롤러 블프로 가면 카테고리 HUD가 뜬다. 여기에 위젯 지정
	TSubclassOf<UUserWidget> HUDWidgetClass; // 만든 위젯 가져오기
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HUD")
	UUserWidget* HUDWidgetInstance; //현재 적용하고 있는 뷰포트

	UFUNCTION(Client, Reliable) //클라이언트 rpc . / 앞에 구별가게 이름 써주기
	void ClientSetMyTurn();

	UFUNCTION(Client, Reliable)
	void ClientSetOtherTurn();

	UFUNCTION(Server, Reliable) //서버 rpc
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