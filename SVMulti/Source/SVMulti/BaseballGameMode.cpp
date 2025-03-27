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
    if (!PlayerController) //플레이어 컨트롤러가 없다 
    {
        return; //리턴
    }

    // 스트라이크와 볼 계산
    int32 Strike = 0;
    int32 Ball = 0;

    // 입력이 3자리인지 확인
    if (InputNumberStr.Len() != DIGITS_COUNT || ServerNumber.Len() != DIGITS_COUNT) //숫자 길이가 3개가 아니거나 || 서버넘버의 길이가 3개가 아니거나 //정확한 숫자 기입이 필요
    {
        return; //리턴 
    }

    // 스트라이크와 볼 계산
    for (int32 i = 0; i < DIGITS_COUNT; i++) //0부터 DIGITS_COUNT(3) , 0,1,2의 자리를 비워라
    {
        if (InputNumberStr[i] == ServerNumber[i]) //FSting이니까 []에 0하면 첫번째 글자, 1하면 두번째 글자 
        {
            Strike++; //숫자도, 자릿수도 같으묜 스트라아크
        }
        else if (ServerNumber.Contains(FString(1, &InputNumberStr[i]))) //Contains(포함하고 있나) / InputNumberStr(인덱스로 생각) 주소값인데 
        {
            Ball++;
        }
    }

    // 클라이언트에게 결과 전송
    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It) //각 클라이언트에게 줘야하니 다 불러와랏
    {
        if (ABaseballPlayerController* PC = Cast<ABaseballPlayerController>(*It))
        {
            PC->ClientReceiveResult(InputNumberStr, Strike, Ball); //서버에서 클라로 알려줘야 한다. 스트라이크,볼로 0S2B같이 알려주기 /InputNumberStr 내가 입력한 숫자
        }
    }

    // 게임 종료 확인
    if (Strike == DIGITS_COUNT)
    {
        GetWorld()->GetTimerManager().ClearTimer(TurnTimerHandle); // 정답이면 멈춰야 해서 클리어 타이머
        GetWorld()->GetTimerManager().ClearTimer(UpdateTimerHandle);

        PlayerController->ClientOnGameWin(); //클라이언트rpc 호출

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


//로그인 개념
void ABaseballGameMode::PostLogin(APlayerController* NewPlayer) //게임 시작할 때 실행이 되는 것 (비긴플레이 이전에) / 플레이어 컨트롤러를 포인터로 가져옴
{
    Super::PostLogin(NewPlayer);

    if (ABaseballPlayerController* PC = Cast<ABaseballPlayerController>(NewPlayer))  
    {
        PlayerControllers.Add(PC); // 플레이어 컨트롤러가 들어오면 하나씩 추가
        MaxPlayer++; //2명으로 지정
    }
}

void ABaseballGameMode::StartGame()
{
    ServerNumber = GenerateRandomNumber(3); //결과를 반환한 것을 ServerNumber에 저장 //퍼블릭에 넣으면 해킹 당할 수 있다는 소식이...
    //랜덤 숫자 뽑고
    PickRandomFirstTurnPlayer(); //첫번째 순서를 누구를 할 거냐
    //턴 정하고
    StartTurnTimer(); //타이머 스따또
    //타이머가 실행을 하고
}

FString ABaseballGameMode::GenerateRandomNumber(const int32 DigitCount) //const = 변경 시키지마 //여기서는 DigitCount
{
    TArray<int32> Digits; // Digits = 자릿수 // 배열사용
    while (Digits.Num() < DigitCount) //배열의 개수가 3보다 작으면 아래걸 계속 시작해라
    {
        int32 RandDigit = FMath::RandRange(1, 9); //1~9부터 숫자를 
        if (!Digits.Contains(RandDigit)) //이 배열에 숫자가 포함이 안되면! 
        {
            Digits.Add(RandDigit); //이 배열에 랜덤 숫자를 넣어달라
        }
    }

    //위에서 3자리 완성 시 
    FString Result; //변수 결과 스트링
    for (int32 Num : Digits) //자릿수를 하나씩 결과에 넣어주다
    {
        Result.AppendInt(Num); //Result에 넣어주는 거
    }

    if (GEngine) //엔진이 실행되면 
    {
        GEngine->AddOnScreenDebugMessage(
            -1,
            5.0f,
            FColor::Yellow,
            FString::Printf(TEXT("Generated Number: %s"), *Result)  // 정답을 미리 알려주는 거 / 우리가 맞추기 어려우니,,,, 추후 삭제
        );
    }

    return Result; //결과 반환
}

void ABaseballGameMode::PickRandomFirstTurnPlayer()
{
    if (PlayerControllers.Num() < MaxPlayer) return; //플레이어 컨트롤러가 맥스 플레이어보다 적으면 반환 / 최대인원 2명

    int32 RandomIndex = FMath::RandRange(0, PlayerControllers.Num() - 1); //RandRange = 1~9 숫자 무작위 뽑기 //RandomIndex 0하고 1중에 아무거나 설정

    ABaseballGameState* GS = GetGameState <ABaseballGameState>(); //게임 스테이트를 GS라는 변수로, 포인터로 가져옴
    if (GS) //GS가 존재하면 
    {
        GS->SetCurrentTurnPlayer(PlayerControllers[RandomIndex]); //SetCurrentTurnPlayer - 현재 플레이어 컨트롤러, 뉴턴플레이어를 랜덤 인덱스에 넣어주기
    }
}

void ABaseballGameMode::StartTurnTimer()
{
    // 기존의 턴 타이머 취소
    GetWorld()->GetTimerManager().ClearTimer(TurnTimerHandle); //기존에 있을 수 있는 타이머를 없애주기
    GetWorld()->GetTimerManager().ClearTimer(UpdateTimerHandle);

    // GameState의 남은 시간 초기화
    ABaseballGameState* GS = Cast<ABaseballGameState>(GameState); //게임 스테이트를 가져와서 
    if (GS)
    {
        GS->SetCurrentTurnTimeRemaining(TurnTimeLimit); //SetCurrentTurnTimeRemaining값을 10초로 지정 
    }

    // 새로운 턴 타이머 설정
    GetWorld()->GetTimerManager().SetTimer( 
        TurnTimerHandle, //타이머핸들 여기서 설정
        this,
        &ABaseballGameMode::HandleTurnTimeout, // 타임아웃이라는 핸들을
        TurnTimeLimit, //10초 지났을때
        false //한번만 호출
    );

    GetWorld()->GetTimerManager().SetTimer(
        UpdateTimerHandle, 
        this,
        &ABaseballGameMode::UpdateTurnTimeRemaining,
        0.1f,
        true //시간 업데이트 0.1초마다 반복해서 계속 호출
    );
}

void ABaseballGameMode::Ready()
{
    if (GetReadyCount() == MaxPlayer) //플레이어 2명 들어오면
    {
        StartGame(); // 시작
    }
}

void ABaseballGameMode::HandleTurnTimeout()
{
    // 타이머 중지
    GetWorld()->GetTimerManager().ClearTimer(TurnTimerHandle); //시간이 지났으니 클린하게 해준다
    GetWorld()->GetTimerManager().ClearTimer(UpdateTimerHandle);

    NextTurn(); //다음 차례
}

void ABaseballGameMode::UpdateTurnTimeRemaining()
{
    ABaseballGameState* GS = Cast<ABaseballGameState>(GameState);
    if (!GS) return; //스테이트가 없으면 리턴해주고

    if (!GetWorld()->GetTimerManager().IsTimerActive(TurnTimerHandle)) //턴타이머 핸들이 작동하고 있는 걸 확인하는 것 /(앞에 느낌표=부정)비활성화 상태면 업데이트 타이머도 중지
    {
        // 타이머가 비활성 상태인 경우 업데이트 타이머도 중지
        GetWorld()->GetTimerManager().ClearTimer(UpdateTimerHandle);
        return;
    }

    float RemainingTime = GetWorld()->GetTimerManager().GetTimerRemaining(TurnTimerHandle);  //턴타이머 핸들의 남은 시간을 RemainingTime 변수에 저장 //앞에 .이 있다 GetTimerManager에 GetTimerRemaining이 있는 거 이런 식으로 속한 애들임 

    // 유효한 범위 확인 및 보정
    if (RemainingTime < 0.0f || RemainingTime > TurnTimeLimit || !FMath::IsFinite(RemainingTime)) //0초 이하거나 10초 이상이거나
    {
        RemainingTime = TurnTimeLimit; // 존재하지 않으면 TurnTimeLimit을 RemainingTime으로 넣고
    }

    // GameState의 복제 변수 업데이트
    GS->SetCurrentTurnTimeRemaining(RemainingTime); //다시 10초로 세팅

    // 모든 플레이어에게 시간 업데이트 알림
    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It) //각 클라에 알리기
    {
        ABaseballPlayerController* PC = Cast<ABaseballPlayerController>(*It);
        if (PC)
        {
            PC->ClientUpdateTurnTime(GS->GetCurrentTurnTimeRemaining()); //시간 바뀌었도다 
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
    if (!HasAuthority()) return; //서버인지 확인 / 아니면 리턴

    if (!PlayerControllers.Contains(RequestingPC)) return; //플레이어 컨트롤러가 RequestingPC 재시작 버튼을 누른 플레이어 컨트롤러(this)말곤 포함하지 않는다
    // 나와 너 둘이 하는 다른 한명이 낄 수 없게 막아주는 것.
    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It) //플레이어 컨트롤러 하나씩 가져와서 형변환 해주고
    {
        ABaseballPlayerController* PC = Cast<ABaseballPlayerController>(*It);
        if (PC)
        {
            PC->ClientResettingbuttons(); //리셋팅하면
        }
    }

    StartGame(); //스따또 (진행했던대로 , 서버에서 숫자 정해주고, 턴 정해주고 등
}

void ABaseballGameMode::BeginPlay() //2번째로 실행 / 게임 모드 비긴플레이가 제일 먼저 실행 - 스테이트 - 컨트롤러 - 위젯 순서
{
    Super::BeginPlay();
}