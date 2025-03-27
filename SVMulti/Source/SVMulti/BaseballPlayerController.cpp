#include "BaseballPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "BaseballGameMode.h"
#include "BaseballGameState.h"

ABaseballPlayerController::ABaseballPlayerController()
	: HUDWidgetClass(nullptr),
	HUDWidgetInstance(nullptr)
{
}

void ABaseballPlayerController::ClientSetMyTurn_Implementation()  //마이턴 //rpc니까 Implementation 붙이고 
{
	UMyUserWidget* MainWidget = Cast<UMyUserWidget>(HUDWidgetInstance); //UMyUserWidget 부모 클래스를 가져와서 MainWidget으로 형변환
	if (MainWidget)
	{
		MainWidget->SetAllButtonsEnabled(true); // 꺼진 버튼 활성화
		MainWidget->ClearGuessNumberTextMessage();
		MainWidget->ShowSignMessage(TEXT("ME"));
	}
}

void ABaseballPlayerController::ClientSetOtherTurn_Implementation()
{
	UMyUserWidget* MainWidget = Cast<UMyUserWidget>(HUDWidgetInstance);
	if (MainWidget)
	{
		MainWidget->SetAllButtonsEnabled(false);
		MainWidget->ClearGuessNumberTextMessage();
		MainWidget->ShowSignMessage(TEXT("YOU"));
	}
}

void ABaseballPlayerController::ServerSubmitGuess_Implementation(const FString& InputNumber)
{
	if (GetWorld())
	{
		ABaseballGameMode* GM = Cast<ABaseballGameMode>(GetWorld()->GetAuthGameMode());
		if (GM)
		{
			GM->CheckAnswer(this, InputNumber); //this = 자기 자신 객체 = 플레이어 컨트롤러를 매개변수로 넣어준 것
		}
	}
}

void ABaseballPlayerController::ClientReceiveResult_Implementation(const FString& InputNumber, int32 Strike, int32 Ball)
{
	UMyUserWidget* MainWidget = Cast<UMyUserWidget>(HUDWidgetInstance);
	if (MainWidget)
	{
		MainWidget->ShowJudgementResult(InputNumber, Strike, Ball); //위젯이 있다면 판단의 결과를 보여준다 ex) 1B 2S 이런 거
	}
}

void ABaseballPlayerController::ClientUpdateTurnTime_Implementation(float RemainingTime)
{
	UMyUserWidget* MainWidget = Cast<UMyUserWidget>(HUDWidgetInstance);
	if (MainWidget)
	{
		MainWidget->UpdateTurnTimeDisplay(RemainingTime);
	}
}

void ABaseballPlayerController::ClientShowMessage_Implementation(const FString& Message)
{
	UMyUserWidget* MainWidget = Cast<UMyUserWidget>(HUDWidgetInstance);
	if (MainWidget)
	{
		MainWidget->ShowSignMessage(Message);
	}
}

void ABaseballPlayerController::ClientOnGameWin_Implementation() 
{
	UMyUserWidget* MainWidget = Cast<UMyUserWidget>(HUDWidgetInstance);
	if (MainWidget)
	{
		MainWidget->ShowGameWinMessage(); //이겼다는 걸 알려줘야함 - 이겼다는 말을 보여주고 / 멘트는 위젯에
		MainWidget->SetAllButtonsEnabled(false); //모든 버튼 다운! = 입력 불가 상태
		MainWidget->SetRestartButtonVisible(true); //하지만 재시작 버튼은 눌리게 한다.
	}
}

void ABaseballPlayerController::ClientOnGameLose_Implementation()
{
	UMyUserWidget* MainWidget = Cast<UMyUserWidget>(HUDWidgetInstance);
	if (MainWidget)
	{
		MainWidget->ShowGameLoseMessage(); //졌다는 멘트
		MainWidget->SetAllButtonsEnabled(false);
		MainWidget->SetRestartButtonVisible(true);
	}
}

void ABaseballPlayerController::ServerRequestRestart_Implementation()
{
	ABaseballGameMode* GM = Cast<ABaseballGameMode>(GetWorld()->GetAuthGameMode()); //겜모를 형변환
	if (GM)
	{
		GM->RequestRestartGame(this); //this는 여기서 플레이어 컨트롤러 호출
	}
}

void ABaseballPlayerController::ClientResettingbuttons_Implementation()
{
	UMyUserWidget* MainWidget = Cast<UMyUserWidget>(HUDWidgetInstance); //위젯의 인스턴스를 가져와서
	if (MainWidget)
	{
		MainWidget->ResetUI();
	}
}

void ABaseballPlayerController::ServerSendReadyValue_Implementation(bool IsReady)  //정의는 ServerSendReadyValue인데 구현할 때는 Implementation(구현)이 붙는다 
{
	if (IsReady) //트루가 들어와서 준비됐다 - IsLocalController
	{
		ABaseballGameMode* GM = Cast<ABaseballGameMode>(GetWorld()->GetAuthGameMode()); //현재 월드에 게임모드를 나의 베이스볼게임모드로 형변환
		{
			GM->ReadyCount++; //ReadyCount가 처음에 0 
			UE_LOG(LogTemp, Warning, TEXT("Received value: %d"), GM->ReadyCount); // 카운트를 안에 넣어서 로그를 출력 - 확인은 아웃풋 로그

			if (HasAuthority()) //서버에서 확인
			{
				if (GM->ReadyCount == 2) //2명이면 준비가 완료됐다.
				{
					GM->Ready(); //스따또
				}
			}
		}
	}
}

void ABaseballPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocalController()) //인스턴스가 클라이언트인지 확인   // 클라에서는 바로 실행이 됨 - 클라니까 //서버, 클라 같이 가지고 있는 애는 컨트롤러 두개가 있으니 클라꺼만 확인을 한 거다잉./클라만 따로있는애
	{
		CreateWidgetOnViewport(); //위젯 생성 후 뷰포트에 붙여넣기
		ServerSendReadyValue(true); // 준비됐는지 확인하고 서버에 전달해주기
		//rpc - / 클라이언트에서 서버에 이것 좀 해줘 = 서버rpc / 서버에서 클라이언트에 이것 좀 해줘 = 클라이언트rpc  
		// 똥침을 손침이라 안하듯이(손이 똥꼬에) 당한 놈이 앞에 붙는다 / 클라가 서버에게 = 서버rpc
	}
}

void ABaseballPlayerController::CreateWidgetOnViewport()
{
	if (HUDWidgetClass)
	{
		HUDWidgetInstance = CreateWidget<UUserWidget>(this, HUDWidgetClass);
		if (HUDWidgetInstance) //현재 적용하고 있는 위젯 인스턴스가 있다 (블프에 붙였다.)
		{
			HUDWidgetInstance->AddToViewport(); // - 뷰포트에 추가하라
		}
	}
}