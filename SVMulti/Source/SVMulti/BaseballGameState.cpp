#include "BaseballGameState.h"
#include "Net/UnrealNetwork.h"
#include "BaseballGameMode.h"
#include "BaseballPlayerController.h"
#include "MyUserWidget.h"
#include "Kismet/GameplayStatics.h"

ABaseballGameState::ABaseballGameState()
{
}

void ABaseballGameState::SetCurrentTurnPlayer(APlayerController* NewTurnPlayer) //컨트롤러가 넘어왔으니 실행이 된다. // 첫 시작을 서버에서 선택해줘야 하니
{
    if (!HasAuthority()) //서버인지 아닌지 확인 /로컬과 다르다
    {
        ensureAlways(false); //추후에 공부
        return; //느낌표가 붙었으니 = 부정 / 서버가 아니면 반환해라
    }

    CurrentTurnPlayer = NewTurnPlayer; //컨트롤러 대입 시키기 

    //if (GetNetMode() != NM_DedicatedServer) //가진 서버가 데디케이트 서버인지 확인 / 하지만 우린 리슨서버임
    //{
    OnCurrentTurnPlayerChanged(); //리슨 서버임으로 실행하기 
    //}
}

void ABaseballGameState::OnRep_CurrentTurnPlayer() //호출하면
{
    OnCurrentTurnPlayerChanged(); //이게 바뀐다  //이걸 감싸준 느낌
}

void ABaseballGameState::OnCurrentTurnPlayerChanged() 
{
    // 모든 플레이어에게 턴 변경 알림
    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It) //플레이어가 두명(0,1) 그거를 반복으로 하나씩 가져오는 것 
    {
        ABaseballPlayerController* PC = Cast<ABaseballPlayerController>(*It); //인덱스 = 주소 / 주소에다가 *(포인터)를 하면 값이 된다.
        if (!PC) continue; //만약 플레이어 컨트롤러가 없다. 그럼 진행혀

        if (PC == CurrentTurnPlayer) // 만약에 있다
        {
            PC->ClientSetMyTurn(); //마이턴 / 클라이언트 rpc - 서버가 클라에게 에헤이 호출해줘  //지금 이게 rpc가 두번 겹친 상황 근데 고치는 방법 흠.... 
        }
        else
        {
            PC->ClientSetOtherTurn(); //유어턴 / 서버 rpc
        }
    }
}

void ABaseballGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ABaseballGameState, CurrentTurnPlayer); //보라색(DOREPLIFETIME)이 CurrentTurnPlayer이걸 네트워크상에 복제로 파악중
    DOREPLIFETIME(ABaseballGameState, CurrentTurnTimeRemaining); //현재 시간이 얼만큼 남았는지 서버에서 각 클라에게 계속 알려주기
}