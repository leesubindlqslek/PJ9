#include "MyUserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Blueprint/WidgetTree.h"
#include "BaseballPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "BaseballGameMode.h"


void UMyUserWidget::NativeConstruct()
{
    Super::NativeConstruct();

    SetRestartButtonVisible(false);
    SetAllButtonsEnabled(true);


    if (Button_1) Button_1->OnClicked.AddDynamic(this, &UMyUserWidget::OnNumberButtonClicked1);
    if (Button_2) Button_2->OnClicked.AddDynamic(this, &UMyUserWidget::OnNumberButtonClicked2);
    if (Button_3) Button_3->OnClicked.AddDynamic(this, &UMyUserWidget::OnNumberButtonClicked3);
    if (Button_4) Button_4->OnClicked.AddDynamic(this, &UMyUserWidget::OnNumberButtonClicked4);
    if (Button_5) Button_5->OnClicked.AddDynamic(this, &UMyUserWidget::OnNumberButtonClicked5);
    if (Button_6) Button_6->OnClicked.AddDynamic(this, &UMyUserWidget::OnNumberButtonClicked6);
    if (Button_7) Button_7->OnClicked.AddDynamic(this, &UMyUserWidget::OnNumberButtonClicked7);
    if (Button_8) Button_8->OnClicked.AddDynamic(this, &UMyUserWidget::OnNumberButtonClicked8);
    if (Button_9) Button_9->OnClicked.AddDynamic(this, &UMyUserWidget::OnNumberButtonClicked9);
    if (ResetButton) ResetButton->OnClicked.AddDynamic(this, &UMyUserWidget::OnResetButtonClicked);
    if (BackspaceButton) BackspaceButton->OnClicked.AddDynamic(this, &UMyUserWidget::OnBackspceButtonClicked);
    if (GuessButton) GuessButton->OnClicked.AddDynamic(this, &UMyUserWidget::OnGuessButtonClicked);
    if (RestartButton) RestartButton->OnClicked.AddDynamic(this, &UMyUserWidget::OnRestartButtonClicked); //Ŭ���ϸ� OnRestartButtonClicked�� �Լ��� ȣ�� (�Ʒ���)

}

void UMyUserWidget::OnNumberButtonClicked1() { if (AppendNumberToGuessText(TEXT("1"))) { SetButtonsDisenabled('1'); } };
void UMyUserWidget::OnNumberButtonClicked2() { if (AppendNumberToGuessText(TEXT("2"))) { SetButtonsDisenabled('2'); } };
void UMyUserWidget::OnNumberButtonClicked3() { if (AppendNumberToGuessText(TEXT("3"))) { SetButtonsDisenabled('3'); } };
void UMyUserWidget::OnNumberButtonClicked4() { if (AppendNumberToGuessText(TEXT("4"))) { SetButtonsDisenabled('4'); } };
void UMyUserWidget::OnNumberButtonClicked5() { if (AppendNumberToGuessText(TEXT("5"))) { SetButtonsDisenabled('5'); } };
void UMyUserWidget::OnNumberButtonClicked6() { if (AppendNumberToGuessText(TEXT("6"))) { SetButtonsDisenabled('6'); } };
void UMyUserWidget::OnNumberButtonClicked7() { if (AppendNumberToGuessText(TEXT("7"))) { SetButtonsDisenabled('7'); } };
void UMyUserWidget::OnNumberButtonClicked8() { if (AppendNumberToGuessText(TEXT("8"))) { SetButtonsDisenabled('8'); } };
void UMyUserWidget::OnNumberButtonClicked9() { if (AppendNumberToGuessText(TEXT("9"))) { SetButtonsDisenabled('9'); } };

bool UMyUserWidget::AppendNumberToGuessText(const FString& NumberStr)
{
    FString CurrentText = GuessNumberText->GetText().ToString();

    if (CurrentText.Len() >= ABaseballGameMode::GetDigitsCount()) return false;

    CurrentText.Append(NumberStr);
    GuessNumberText->SetText(FText::FromString(CurrentText));

    return true;
}

void UMyUserWidget::OnBackspceButtonClicked()
{
    if (!GuessNumberText) return;

    FString CurrentText = GuessNumberText->GetText().ToString();
    if (CurrentText.Len() > 0)
    {
        // ������ ���� ����
        TCHAR LastChar = CurrentText[CurrentText.Len() - 1];

        // ���ڿ����� ����
        CurrentText.LeftChopInline(1);
        GuessNumberText->SetText(FText::FromString(CurrentText));

        SetButtonsEnabled(LastChar);
    }
}

void UMyUserWidget::OnResetButtonClicked() //����
{
    if (GuessNumberText) //���� �Է� �ؽ�Ʈ
    {
        GuessNumberText->SetText(FText::FromString(TEXT(""))); //�� ��ĭ���� ������ֱ� 
    }

    SetAllButtonsEnabled(true); // ������ ��Ȱ��ȭ�� ��ư�� �ٽ� Ȱ��ȭ 
}

void UMyUserWidget::OnGuessButtonClicked()
{
    FString InputText = GuessNumberText->GetText().ToString();

    // �Է� Ȯ�� - 3�ڸ� �ƴϸ� ���
    if (InputText.Len() != ABaseballGameMode::GetDigitsCount())
    {
        ShowSignMessage(TEXT("3�ڸ�"));
        GuessNumberText->SetText(FText::FromString(TEXT("")));

        SetAllButtonsEnabled(true);
        return;
    }

    ABaseballPlayerController* PC = Cast<ABaseballPlayerController>(GetOwningPlayer());
    if (PC)
    {
        PC->ServerSubmitGuess(InputText);
    }

    ClearGuessNumberTextMessage(); //���� �Է� �� �Է� ��ư�� ������ ���ڰ� ���������� ����
}

void UMyUserWidget::OnRestartButtonClicked() //�����
{
    ABaseballPlayerController* PC = Cast<ABaseballPlayerController>(GetOwningPlayer()); //����ŸƮ ��ư�� ������ �÷��̾� ��Ʈ�ѷ��� �����ͼ�
    if (PC)
    {
        PC->ServerRequestRestart(); //ServerRequestRestartȣ��
    }
}

void UMyUserWidget::SetButtonsEnabled(TCHAR NumberChar)
{
    switch (NumberChar)
    {
    case '1': if (Button_1) Button_1->SetIsEnabled(true); break;
    case '2': if (Button_2) Button_2->SetIsEnabled(true); break;
    case '3': if (Button_3) Button_3->SetIsEnabled(true); break;
    case '4': if (Button_4) Button_4->SetIsEnabled(true); break;
    case '5': if (Button_5) Button_5->SetIsEnabled(true); break;
    case '6': if (Button_6) Button_6->SetIsEnabled(true); break;
    case '7': if (Button_7) Button_7->SetIsEnabled(true); break;
    case '8': if (Button_8) Button_8->SetIsEnabled(true); break;
    case '9': if (Button_9) Button_9->SetIsEnabled(true); break;
    }
}

void UMyUserWidget::SetButtonsDisenabled(TCHAR NumberChar)
{
    switch (NumberChar)
    {
    case '1': if (Button_1) Button_1->SetIsEnabled(false); break;
    case '2': if (Button_2) Button_2->SetIsEnabled(false); break;
    case '3': if (Button_3) Button_3->SetIsEnabled(false); break;
    case '4': if (Button_4) Button_4->SetIsEnabled(false); break;
    case '5': if (Button_5) Button_5->SetIsEnabled(false); break;
    case '6': if (Button_6) Button_6->SetIsEnabled(false); break;
    case '7': if (Button_7) Button_7->SetIsEnabled(false); break;
    case '8': if (Button_8) Button_8->SetIsEnabled(false); break;
    case '9': if (Button_9) Button_9->SetIsEnabled(false); break;
    }
}

void UMyUserWidget::SetAllButtonsEnabled(bool bEnable) //��� ��ư�� �����ϰ� bool�� Ʈ�簡 ������ �� �����ϰ� 
{
    if (WidgetTree) //��� ��ư��
    {
        TArray<UWidget*> AllWidgets;
        WidgetTree->GetAllWidgets(AllWidgets);

        for (UWidget* Widget : AllWidgets)
        {
            if (UButton* Button = Cast<UButton>(Widget))
            {
                Button->SetIsEnabled(bEnable);
            }
        }
    }
}

void UMyUserWidget::ShowSignMessage(const FString& Message)
{
    if (SignText)
    {
        SignText->SetText(FText::FromString(Message));
    }
}

void UMyUserWidget::ShowJudgementResult(const FString& InputNumber, int32 Strike, int32 Ball)
{
    FString ResultText = FString::Printf(TEXT("%s: %d S, %d B"), *InputNumber, Strike, Ball); //���� /%s = string(���ڿ�) (�׳� ���ڴ� C) / %D = ����

    if (JudgementText) //������� ������

    {
        JudgementText->SetText(FText::FromString(ResultText)); //���� �� �ؽ�Ʈ�� ����ش�.
    }
}

void UMyUserWidget::ClearGuessNumberTextMessage()
{
    if (GuessNumberText)
    {
        GuessNumberText->SetText(FText::FromString(TEXT(""))); //�����ϰ� �����ֱ�
    }
}

void UMyUserWidget::ClearJudgementTextMessage()
{
    if (JudgementText)
    {
        JudgementText->SetText(FText::FromString(TEXT("")));
    }
}

void UMyUserWidget::UpdateTurnTimeDisplay(float RemainingTime)
{
    if (TimerText)
    {
        FString TimeString = FString::Printf(TEXT("%.1f��"), RemainingTime);

        TimerText->SetText(FText::FromString(TimeString));
    }
}

void UMyUserWidget::ShowGameWinMessage()
{
    if (SignText)
    {
        SignText->SetText(FText::FromString(TEXT("You Win")));
    }
}

void UMyUserWidget::ShowGameLoseMessage()
{
    if (SignText)
    {
        SignText->SetText(FText::FromString(TEXT("You Lose")));
    }
}

void UMyUserWidget::SetRestartButtonVisible(bool bVisible)  // bVisible�̶�� �Ҹ������� �Ǵ�
{
    if (!bVisible) //���̰� �ϳ� �ƴϳ� /����ǥ�� �մ� �������̾�
    {
        RestartButton->SetVisibility(ESlateVisibility::Collapsed); //�Ⱥ��̰�
    }
    else
    {
        RestartButton->SetVisibility(ESlateVisibility::Visible);  //�̰����� ���̰� ���� �� �ְ�
        RestartButton->SetIsEnabled(true);
    }
}

void UMyUserWidget::ResetUI() // �ؽ�Ʈ �ڽ��� �ִ� �� ���� ������ �����
{
    if (GuessNumberText) GuessNumberText->SetText(FText::FromString(TEXT("")));
    if (SignText) SignText->SetText(FText::FromString(TEXT("")));
    if (JudgementText) JudgementText->SetText(FText::FromString(TEXT("")));
    if (TimerText) TimerText->SetText(FText::FromString(TEXT("")));

    SetAllButtonsEnabled(true); //�����̴ϱ� ��ư Ȱ��ȭ
    SetRestartButtonVisible(false); // ������� ������ ����� ��ư�� �ٽ� �� ���̰� ����
}
