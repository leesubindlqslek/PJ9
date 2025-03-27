#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

UCLASS()
class SVMULTI_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

private:

    // 숫자 버튼
    UPROPERTY(meta = (BindWidget)) UButton* Button_1;
    UPROPERTY(meta = (BindWidget)) UButton* Button_2;
    UPROPERTY(meta = (BindWidget)) UButton* Button_3;
    UPROPERTY(meta = (BindWidget)) UButton* Button_4;
    UPROPERTY(meta = (BindWidget)) UButton* Button_5;
    UPROPERTY(meta = (BindWidget)) UButton* Button_6;
    UPROPERTY(meta = (BindWidget)) UButton* Button_7;
    UPROPERTY(meta = (BindWidget)) UButton* Button_8;
    UPROPERTY(meta = (BindWidget)) UButton* Button_9;

    UPROPERTY(meta = (BindWidget)) UButton* GuessButton;
    UPROPERTY(meta = (BindWidget)) UButton* ResetButton;
    UPROPERTY(meta = (BindWidget)) UButton* BackspaceButton;
    UPROPERTY(meta = (BindWidget)) UButton* RestartButton;

    // 텍스트 블록
    UPROPERTY(meta = (BindWidget)) UTextBlock* GuessNumberText;
    UPROPERTY(meta = (BindWidget)) UTextBlock* SignText;
    UPROPERTY(meta = (BindWidget)) UTextBlock* JudgementText;
    UPROPERTY(meta = (BindWidget)) UTextBlock* TimerText;

    UFUNCTION()
    void OnNumberButtonClicked1();
    UFUNCTION()
    void OnNumberButtonClicked2();
    UFUNCTION()
    void OnNumberButtonClicked3();
    UFUNCTION()
    void OnNumberButtonClicked4();
    UFUNCTION()
    void OnNumberButtonClicked5();
    UFUNCTION()
    void OnNumberButtonClicked6();
    UFUNCTION()
    void OnNumberButtonClicked7();
    UFUNCTION()
    void OnNumberButtonClicked8();
    UFUNCTION()
    void OnNumberButtonClicked9();

protected:
    virtual void NativeConstruct() override;

    bool AppendNumberToGuessText(const FString& NumberStr);

    UFUNCTION()
    void OnBackspceButtonClicked();

    UFUNCTION()
    void OnResetButtonClicked();

    UFUNCTION()
    void OnGuessButtonClicked();

    UFUNCTION()
    void OnRestartButtonClicked();

    void SetButtonsEnabled(TCHAR NumberChar);
    void SetButtonsDisenabled(TCHAR NumberChar);

public:
    void SetAllButtonsEnabled(bool bEnable);

    void ShowSignMessage(const FString& Message);
    void ShowJudgementResult(const FString& InputNumber, int32 Strike, int32 Ball);

    void ClearGuessNumberTextMessage();
    void ClearJudgementTextMessage();

    void UpdateTurnTimeDisplay(float RemainingTime);

    void ShowGameWinMessage();
    void ShowGameLoseMessage();

    void SetRestartButtonVisible(bool bVisible);

    void ResetUI();
};
