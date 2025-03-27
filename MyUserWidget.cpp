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
    if (RestartButton) RestartButton->OnClicked.AddDynamic(this, &UMyUserWidget::OnRestartButtonClicked); //클릭하면 OnRestartButtonClicked이 함수가 호출 (아래로)

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
        // 마지막 문자 추출
        TCHAR LastChar = CurrentText[CurrentText.Len() - 1];

        // 문자열에서 제거
        CurrentText.LeftChopInline(1);
        GuessNumberText->SetText(FText::FromString(CurrentText));

        SetButtonsEnabled(LastChar);
    }
}

void UMyUserWidget::OnResetButtonClicked() //리셋
{
    if (GuessNumberText) //점수 입력 텍스트
    {
        GuessNumberText->SetText(FText::FromString(TEXT(""))); //를 빈칸으로 만들어주기 
    }

    SetAllButtonsEnabled(true); // 눌러서 비활성화된 버튼을 다시 활성화 
}

void UMyUserWidget::OnGuessButtonClicked()
{
    FString InputText = GuessNumberText->GetText().ToString();

    // 입력 확인 - 3자리 아니면 경고
    if (InputText.Len() != ABaseballGameMode::GetDigitsCount())
    {
        ShowSignMessage(TEXT("3자리"));
        GuessNumberText->SetText(FText::FromString(TEXT("")));

        SetAllButtonsEnabled(true);
        return;
    }

    ABaseballPlayerController* PC = Cast<ABaseballPlayerController>(GetOwningPlayer());
    if (PC)
    {
        PC->ServerSubmitGuess(InputText);
    }

    ClearGuessNumberTextMessage(); //글자 입력 후 입력 버튼을 누르면 글자가 지워지도록 설정
}

void UMyUserWidget::OnRestartButtonClicked() //재시작
{
    ABaseballPlayerController* PC = Cast<ABaseballPlayerController>(GetOwningPlayer()); //리스타트 버튼을 누르면 플레이어 컨트롤러를 가져와서
    if (PC)
    {
        PC->ServerRequestRestart(); //ServerRequestRestart호출
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

void UMyUserWidget::SetAllButtonsEnabled(bool bEnable) //모든 버튼을 가능하게 bool로 트루가 들어오면 다 가능하게 
{
    if (WidgetTree) //모든 버튼들
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
    FString ResultText = FString::Printf(TEXT("%s: %d S, %d B"), *InputNumber, Strike, Ball); //점수 /%s = string(문자열) (그냥 문자는 C) / %D = 숫자

    if (JudgementText) //결과값이 있으면

    {
        JudgementText->SetText(FText::FromString(ResultText)); //위에 저 텍스트를 띄어준다.
    }
}

void UMyUserWidget::ClearGuessNumberTextMessage()
{
    if (GuessNumberText)
    {
        GuessNumberText->SetText(FText::FromString(TEXT(""))); //깨끗하게 지워주기
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
        FString TimeString = FString::Printf(TEXT("%.1f초"), RemainingTime);

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

void UMyUserWidget::SetRestartButtonVisible(bool bVisible)  // bVisible이라는 불린값으로 판단
{
    if (!bVisible) //보이게 하냐 아니냐 /느낌표가 잇다 부정문이야
    {
        RestartButton->SetVisibility(ESlateVisibility::Collapsed); //안보이게
    }
    else
    {
        RestartButton->SetVisibility(ESlateVisibility::Visible);  //이겼으니 보이고 누를 수 있게
        RestartButton->SetIsEnabled(true);
    }
}

void UMyUserWidget::ResetUI() // 텍스트 박스에 있는 걸 전부 백지로 만들기
{
    if (GuessNumberText) GuessNumberText->SetText(FText::FromString(TEXT("")));
    if (SignText) SignText->SetText(FText::FromString(TEXT("")));
    if (JudgementText) JudgementText->SetText(FText::FromString(TEXT("")));
    if (TimerText) TimerText->SetText(FText::FromString(TEXT("")));

    SetAllButtonsEnabled(true); //리셋이니까 버튼 활성화
    SetRestartButtonVisible(false); // 재시작을 했으니 재시작 버튼을 다시 안 보이게 설정
}
