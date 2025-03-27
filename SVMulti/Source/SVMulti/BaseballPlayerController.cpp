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

void ABaseballPlayerController::ClientSetMyTurn_Implementation()  //������ //rpc�ϱ� Implementation ���̰� 
{
	UMyUserWidget* MainWidget = Cast<UMyUserWidget>(HUDWidgetInstance); //UMyUserWidget �θ� Ŭ������ �����ͼ� MainWidget���� ����ȯ
	if (MainWidget)
	{
		MainWidget->SetAllButtonsEnabled(true); // ���� ��ư Ȱ��ȭ
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
			GM->CheckAnswer(this, InputNumber); //this = �ڱ� �ڽ� ��ü = �÷��̾� ��Ʈ�ѷ��� �Ű������� �־��� ��
		}
	}
}

void ABaseballPlayerController::ClientReceiveResult_Implementation(const FString& InputNumber, int32 Strike, int32 Ball)
{
	UMyUserWidget* MainWidget = Cast<UMyUserWidget>(HUDWidgetInstance);
	if (MainWidget)
	{
		MainWidget->ShowJudgementResult(InputNumber, Strike, Ball); //������ �ִٸ� �Ǵ��� ����� �����ش� ex) 1B 2S �̷� ��
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
		MainWidget->ShowGameWinMessage(); //�̰�ٴ� �� �˷������ - �̰�ٴ� ���� �����ְ� / ��Ʈ�� ������
		MainWidget->SetAllButtonsEnabled(false); //��� ��ư �ٿ�! = �Է� �Ұ� ����
		MainWidget->SetRestartButtonVisible(true); //������ ����� ��ư�� ������ �Ѵ�.
	}
}

void ABaseballPlayerController::ClientOnGameLose_Implementation()
{
	UMyUserWidget* MainWidget = Cast<UMyUserWidget>(HUDWidgetInstance);
	if (MainWidget)
	{
		MainWidget->ShowGameLoseMessage(); //���ٴ� ��Ʈ
		MainWidget->SetAllButtonsEnabled(false);
		MainWidget->SetRestartButtonVisible(true);
	}
}

void ABaseballPlayerController::ServerRequestRestart_Implementation()
{
	ABaseballGameMode* GM = Cast<ABaseballGameMode>(GetWorld()->GetAuthGameMode()); //�׸� ����ȯ
	if (GM)
	{
		GM->RequestRestartGame(this); //this�� ���⼭ �÷��̾� ��Ʈ�ѷ� ȣ��
	}
}

void ABaseballPlayerController::ClientResettingbuttons_Implementation()
{
	UMyUserWidget* MainWidget = Cast<UMyUserWidget>(HUDWidgetInstance); //������ �ν��Ͻ��� �����ͼ�
	if (MainWidget)
	{
		MainWidget->ResetUI();
	}
}

void ABaseballPlayerController::ServerSendReadyValue_Implementation(bool IsReady)  //���Ǵ� ServerSendReadyValue�ε� ������ ���� Implementation(����)�� �ٴ´� 
{
	if (IsReady) //Ʈ�簡 ���ͼ� �غ�ƴ� - IsLocalController
	{
		ABaseballGameMode* GM = Cast<ABaseballGameMode>(GetWorld()->GetAuthGameMode()); //���� ���忡 ���Ӹ�带 ���� ���̽������Ӹ��� ����ȯ
		{
			GM->ReadyCount++; //ReadyCount�� ó���� 0 
			UE_LOG(LogTemp, Warning, TEXT("Received value: %d"), GM->ReadyCount); // ī��Ʈ�� �ȿ� �־ �α׸� ��� - Ȯ���� �ƿ�ǲ �α�

			if (HasAuthority()) //�������� Ȯ��
			{
				if (GM->ReadyCount == 2) //2���̸� �غ� �Ϸ�ƴ�.
				{
					GM->Ready(); //������
				}
			}
		}
	}
}

void ABaseballPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocalController()) //�ν��Ͻ��� Ŭ���̾�Ʈ���� Ȯ��   // Ŭ�󿡼��� �ٷ� ������ �� - Ŭ��ϱ� //����, Ŭ�� ���� ������ �ִ� �ִ� ��Ʈ�ѷ� �ΰ��� ������ Ŭ�󲨸� Ȯ���� �� �Ŵ���./Ŭ�� �����ִ¾�
	{
		CreateWidgetOnViewport(); //���� ���� �� ����Ʈ�� �ٿ��ֱ�
		ServerSendReadyValue(true); // �غ�ƴ��� Ȯ���ϰ� ������ �������ֱ�
		//rpc - / Ŭ���̾�Ʈ���� ������ �̰� �� ���� = ����rpc / �������� Ŭ���̾�Ʈ�� �̰� �� ���� = Ŭ���̾�Ʈrpc  
		// ��ħ�� ��ħ�̶� ���ϵ���(���� �˲���) ���� ���� �տ� �ٴ´� / Ŭ�� �������� = ����rpc
	}
}

void ABaseballPlayerController::CreateWidgetOnViewport()
{
	if (HUDWidgetClass)
	{
		HUDWidgetInstance = CreateWidget<UUserWidget>(this, HUDWidgetClass);
		if (HUDWidgetInstance) //���� �����ϰ� �ִ� ���� �ν��Ͻ��� �ִ� (������ �ٿ���.)
		{
			HUDWidgetInstance->AddToViewport(); // - ����Ʈ�� �߰��϶�
		}
	}
}