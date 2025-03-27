#include "BaseballGameState.h"
#include "Net/UnrealNetwork.h"
#include "BaseballGameMode.h"
#include "BaseballPlayerController.h"
#include "MyUserWidget.h"
#include "Kismet/GameplayStatics.h"

ABaseballGameState::ABaseballGameState()
{
}

void ABaseballGameState::SetCurrentTurnPlayer(APlayerController* NewTurnPlayer) //��Ʈ�ѷ��� �Ѿ������ ������ �ȴ�. // ù ������ �������� ��������� �ϴ�
{
    if (!HasAuthority()) //�������� �ƴ��� Ȯ�� /���ð� �ٸ���
    {
        ensureAlways(false); //���Ŀ� ����
        return; //����ǥ�� �پ����� = ���� / ������ �ƴϸ� ��ȯ�ض�
    }

    CurrentTurnPlayer = NewTurnPlayer; //��Ʈ�ѷ� ���� ��Ű�� 

    //if (GetNetMode() != NM_DedicatedServer) //���� ������ ��������Ʈ �������� Ȯ�� / ������ �츰 ����������
    //{
    OnCurrentTurnPlayerChanged(); //���� ���������� �����ϱ� 
    //}
}

void ABaseballGameState::OnRep_CurrentTurnPlayer() //ȣ���ϸ�
{
    OnCurrentTurnPlayerChanged(); //�̰� �ٲ��  //�̰� ������ ����
}

void ABaseballGameState::OnCurrentTurnPlayerChanged() 
{
    // ��� �÷��̾�� �� ���� �˸�
    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It) //�÷��̾ �θ�(0,1) �װŸ� �ݺ����� �ϳ��� �������� �� 
    {
        ABaseballPlayerController* PC = Cast<ABaseballPlayerController>(*It); //�ε��� = �ּ� / �ּҿ��ٰ� *(������)�� �ϸ� ���� �ȴ�.
        if (!PC) continue; //���� �÷��̾� ��Ʈ�ѷ��� ����. �׷� ������

        if (PC == CurrentTurnPlayer) // ���࿡ �ִ�
        {
            PC->ClientSetMyTurn(); //������ / Ŭ���̾�Ʈ rpc - ������ Ŭ�󿡰� ������ ȣ������  //���� �̰� rpc�� �ι� ��ģ ��Ȳ �ٵ� ��ġ�� ��� ��.... 
        }
        else
        {
            PC->ClientSetOtherTurn(); //������ / ���� rpc
        }
    }
}

void ABaseballGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ABaseballGameState, CurrentTurnPlayer); //�����(DOREPLIFETIME)�� CurrentTurnPlayer�̰� ��Ʈ��ũ�� ������ �ľ���
    DOREPLIFETIME(ABaseballGameState, CurrentTurnTimeRemaining); //���� �ð��� ��ŭ ���Ҵ��� �������� �� Ŭ�󿡰� ��� �˷��ֱ�
}