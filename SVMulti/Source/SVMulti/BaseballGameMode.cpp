#include "BaseballGameMode.h"
#include "BaseballGameState.h"
#include "BaseballPlayerController.h"


ABaseballGameMode::ABaseballGameMode()
{
	PlayerControllerClass = ABaseballPlayerController::StaticClass();
	GameStateClass = ABaseballGameState::StaticClass();
}

void ABaseballGameMode::CheckAnswer(ABaseballPlayerController* PlayerController, const FString& InputNumberStr)
{
    if (!PlayerController) //�÷��̾� ��Ʈ�ѷ��� ���� 
    {
        return; //����
    }

    // ��Ʈ����ũ�� �� ���
    int32 Strike = 0;
    int32 Ball = 0;

    // �Է��� 3�ڸ����� Ȯ��
    if (InputNumberStr.Len() != DIGITS_COUNT || ServerNumber.Len() != DIGITS_COUNT) //���� ���̰� 3���� �ƴϰų� || �����ѹ��� ���̰� 3���� �ƴϰų� //��Ȯ�� ���� ������ �ʿ�
    {
        return; //���� 
    }

    // ��Ʈ����ũ�� �� ���
    for (int32 i = 0; i < DIGITS_COUNT; i++) //0���� DIGITS_COUNT(3) , 0,1,2�� �ڸ��� �����
    {
        if (InputNumberStr[i] == ServerNumber[i]) //FSting�̴ϱ� []�� 0�ϸ� ù��° ����, 1�ϸ� �ι�° ���� 
        {
            Strike++; //���ڵ�, �ڸ����� ������ ��Ʈ���ũ
        }
        else if (ServerNumber.Contains(FString(1, &InputNumberStr[i]))) //Contains(�����ϰ� �ֳ�) / InputNumberStr(�ε����� ����) �ּҰ��ε� 
        {
            Ball++;
        }
    }

    // Ŭ���̾�Ʈ���� ��� ����
    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It) //�� Ŭ���̾�Ʈ���� ����ϴ� �� �ҷ��Ͷ�
    {
        if (ABaseballPlayerController* PC = Cast<ABaseballPlayerController>(*It))
        {
            PC->ClientReceiveResult(InputNumberStr, Strike, Ball); //�������� Ŭ��� �˷���� �Ѵ�. ��Ʈ����ũ,���� 0S2B���� �˷��ֱ� /InputNumberStr ���� �Է��� ����
        }
    }

    // ���� ���� Ȯ��
    if (Strike == DIGITS_COUNT)
    {
        GetWorld()->GetTimerManager().ClearTimer(TurnTimerHandle); // �����̸� ����� �ؼ� Ŭ���� Ÿ�̸�
        GetWorld()->GetTimerManager().ClearTimer(UpdateTimerHandle);

        PlayerController->ClientOnGameWin(); //Ŭ���̾�Ʈrpc ȣ��

        for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
        {
            if (ABaseballPlayerController* PC = Cast<ABaseballPlayerController>(*It))
            {
                if (PC != PlayerController)
                {
                    PC->ClientOnGameLose();
                }
            }
        }
    }
    else
    {
        NextTurn();
    }
}


//�α��� ����
void ABaseballGameMode::PostLogin(APlayerController* NewPlayer) //���� ������ �� ������ �Ǵ� �� (����÷��� ������) / �÷��̾� ��Ʈ�ѷ��� �����ͷ� ������
{
    Super::PostLogin(NewPlayer);

    if (ABaseballPlayerController* PC = Cast<ABaseballPlayerController>(NewPlayer))  
    {
        PlayerControllers.Add(PC); // �÷��̾� ��Ʈ�ѷ��� ������ �ϳ��� �߰�
        MaxPlayer++; //2������ ����
    }
}

void ABaseballGameMode::StartGame()
{
    ServerNumber = GenerateRandomNumber(3); //����� ��ȯ�� ���� ServerNumber�� ���� //�ۺ��� ������ ��ŷ ���� �� �ִٴ� �ҽ���...
    //���� ���� �̰�
    PickRandomFirstTurnPlayer(); //ù��° ������ ������ �� �ų�
    //�� ���ϰ�
    StartTurnTimer(); //Ÿ�̸� ������
    //Ÿ�̸Ӱ� ������ �ϰ�
}

FString ABaseballGameMode::GenerateRandomNumber(const int32 DigitCount) //const = ���� ��Ű���� //���⼭�� DigitCount
{
    TArray<int32> Digits; // Digits = �ڸ��� // �迭���
    while (Digits.Num() < DigitCount) //�迭�� ������ 3���� ������ �Ʒ��� ��� �����ض�
    {
        int32 RandDigit = FMath::RandRange(1, 9); //1~9���� ���ڸ� 
        if (!Digits.Contains(RandDigit)) //�� �迭�� ���ڰ� ������ �ȵǸ�! 
        {
            Digits.Add(RandDigit); //�� �迭�� ���� ���ڸ� �־�޶�
        }
    }

    //������ 3�ڸ� �ϼ� �� 
    FString Result; //���� ��� ��Ʈ��
    for (int32 Num : Digits) //�ڸ����� �ϳ��� ����� �־��ִ�
    {
        Result.AppendInt(Num); //Result�� �־��ִ� ��
    }

    if (GEngine) //������ ����Ǹ� 
    {
        GEngine->AddOnScreenDebugMessage(
            -1,
            5.0f,
            FColor::Yellow,
            FString::Printf(TEXT("Generated Number: %s"), *Result)  // ������ �̸� �˷��ִ� �� / �츮�� ���߱� ������,,,, ���� ����
        );
    }

    return Result; //��� ��ȯ
}

void ABaseballGameMode::PickRandomFirstTurnPlayer()
{
    if (PlayerControllers.Num() < MaxPlayer) return; //�÷��̾� ��Ʈ�ѷ��� �ƽ� �÷��̾�� ������ ��ȯ / �ִ��ο� 2��

    int32 RandomIndex = FMath::RandRange(0, PlayerControllers.Num() - 1); //RandRange = 1~9 ���� ������ �̱� //RandomIndex 0�ϰ� 1�߿� �ƹ��ų� ����

    ABaseballGameState* GS = GetGameState <ABaseballGameState>(); //���� ������Ʈ�� GS��� ������, �����ͷ� ������
    if (GS) //GS�� �����ϸ� 
    {
        GS->SetCurrentTurnPlayer(PlayerControllers[RandomIndex]); //SetCurrentTurnPlayer - ���� �÷��̾� ��Ʈ�ѷ�, �����÷��̾ ���� �ε����� �־��ֱ�
    }
}

void ABaseballGameMode::StartTurnTimer()
{
    // ������ �� Ÿ�̸� ���
    GetWorld()->GetTimerManager().ClearTimer(TurnTimerHandle); //������ ���� �� �ִ� Ÿ�̸Ӹ� �����ֱ�
    GetWorld()->GetTimerManager().ClearTimer(UpdateTimerHandle);

    // GameState�� ���� �ð� �ʱ�ȭ
    ABaseballGameState* GS = Cast<ABaseballGameState>(GameState); //���� ������Ʈ�� �����ͼ� 
    if (GS)
    {
        GS->SetCurrentTurnTimeRemaining(TurnTimeLimit); //SetCurrentTurnTimeRemaining���� 10�ʷ� ���� 
    }

    // ���ο� �� Ÿ�̸� ����
    GetWorld()->GetTimerManager().SetTimer( 
        TurnTimerHandle, //Ÿ�̸��ڵ� ���⼭ ����
        this,
        &ABaseballGameMode::HandleTurnTimeout, // Ÿ�Ӿƿ��̶�� �ڵ���
        TurnTimeLimit, //10�� ��������
        false //�ѹ��� ȣ��
    );

    GetWorld()->GetTimerManager().SetTimer(
        UpdateTimerHandle, 
        this,
        &ABaseballGameMode::UpdateTurnTimeRemaining,
        0.1f,
        true //�ð� ������Ʈ 0.1�ʸ��� �ݺ��ؼ� ��� ȣ��
    );
}

void ABaseballGameMode::Ready()
{
    if (GetReadyCount() == MaxPlayer) //�÷��̾� 2�� ������
    {
        StartGame(); // ����
    }
}

void ABaseballGameMode::HandleTurnTimeout()
{
    // Ÿ�̸� ����
    GetWorld()->GetTimerManager().ClearTimer(TurnTimerHandle); //�ð��� �������� Ŭ���ϰ� ���ش�
    GetWorld()->GetTimerManager().ClearTimer(UpdateTimerHandle);

    NextTurn(); //���� ����
}

void ABaseballGameMode::UpdateTurnTimeRemaining()
{
    ABaseballGameState* GS = Cast<ABaseballGameState>(GameState);
    if (!GS) return; //������Ʈ�� ������ �������ְ�

    if (!GetWorld()->GetTimerManager().IsTimerActive(TurnTimerHandle)) //��Ÿ�̸� �ڵ��� �۵��ϰ� �ִ� �� Ȯ���ϴ� �� /(�տ� ����ǥ=����)��Ȱ��ȭ ���¸� ������Ʈ Ÿ�̸ӵ� ����
    {
        // Ÿ�̸Ӱ� ��Ȱ�� ������ ��� ������Ʈ Ÿ�̸ӵ� ����
        GetWorld()->GetTimerManager().ClearTimer(UpdateTimerHandle);
        return;
    }

    float RemainingTime = GetWorld()->GetTimerManager().GetTimerRemaining(TurnTimerHandle);  //��Ÿ�̸� �ڵ��� ���� �ð��� RemainingTime ������ ���� //�տ� .�� �ִ� GetTimerManager�� GetTimerRemaining�� �ִ� �� �̷� ������ ���� �ֵ��� 

    // ��ȿ�� ���� Ȯ�� �� ����
    if (RemainingTime < 0.0f || RemainingTime > TurnTimeLimit || !FMath::IsFinite(RemainingTime)) //0�� ���ϰų� 10�� �̻��̰ų�
    {
        RemainingTime = TurnTimeLimit; // �������� ������ TurnTimeLimit�� RemainingTime���� �ְ�
    }

    // GameState�� ���� ���� ������Ʈ
    GS->SetCurrentTurnTimeRemaining(RemainingTime); //�ٽ� 10�ʷ� ����

    // ��� �÷��̾�� �ð� ������Ʈ �˸�
    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It) //�� Ŭ�� �˸���
    {
        ABaseballPlayerController* PC = Cast<ABaseballPlayerController>(*It);
        if (PC)
        {
            PC->ClientUpdateTurnTime(GS->GetCurrentTurnTimeRemaining()); //�ð� �ٲ������ 
        }
    }
}

void ABaseballGameMode::NextTurn()
{
    if (PlayerControllers.Num() == 0) return;

    ABaseballGameState* GS = GetGameState<ABaseballGameState>();
    if (!GS) return;

    int32 CurrentIndex = PlayerControllers.IndexOfByKey(GS->GetCurrentTurnPlayer());
    int32 NextIndex = (CurrentIndex + 1) % PlayerControllers.Num();
    GS->SetCurrentTurnPlayer(PlayerControllers[NextIndex]);

    StartTurnTimer();
}

void ABaseballGameMode::RequestRestartGame(APlayerController* RequestingPC)
{
    if (!HasAuthority()) return; //�������� Ȯ�� / �ƴϸ� ����

    if (!PlayerControllers.Contains(RequestingPC)) return; //�÷��̾� ��Ʈ�ѷ��� RequestingPC ����� ��ư�� ���� �÷��̾� ��Ʈ�ѷ�(this)���� �������� �ʴ´�
    // ���� �� ���� �ϴ� �ٸ� �Ѹ��� �� �� ���� �����ִ� ��.
    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It) //�÷��̾� ��Ʈ�ѷ� �ϳ��� �����ͼ� ����ȯ ���ְ�
    {
        ABaseballPlayerController* PC = Cast<ABaseballPlayerController>(*It);
        if (PC)
        {
            PC->ClientResettingbuttons(); //�������ϸ�
        }
    }

    StartGame(); //������ (�����ߴ���� , �������� ���� �����ְ�, �� �����ְ� ��
}

void ABaseballGameMode::BeginPlay() //2��°�� ���� / ���� ��� ����÷��̰� ���� ���� ���� - ������Ʈ - ��Ʈ�ѷ� - ���� ����
{
    Super::BeginPlay();
}