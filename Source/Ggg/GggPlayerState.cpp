#include "GggPlayerState.h"
#include "Net/UnrealNetwork.h"

void AGggPlayerState::GrantReward(int32 XP, int32 Coins)
{
    if (!HasAuthority() || XP < 0 || Coins < 0) return;
    Gold = int32(FMath::Min<int64>(int64(Gold) + Coins, MAX_int32));
    Experience = int32(FMath::Min<int64>(int64(Experience) + XP, MAX_int32));
    while (HunterLevel < 100 && Experience >= HunterLevel * 100)
    {
        Experience -= HunterLevel * 100;
        ++HunterLevel;
    }
    if (HunterLevel == 100) Experience = 0;
    ForceNetUpdate();
}
FString AGggPlayerState::GetHunterRank() const
{
    if (HunterLevel >= 50) return TEXT("S");
    if (HunterLevel >= 40) return TEXT("A");
    if (HunterLevel >= 30) return TEXT("B");
    if (HunterLevel >= 20) return TEXT("C");
    if (HunterLevel >= 10) return TEXT("D");
    return TEXT("E");
}
void AGggPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(AGggPlayerState, HunterLevel);
    DOREPLIFETIME(AGggPlayerState, Experience);
    DOREPLIFETIME(AGggPlayerState, Gold);
}
