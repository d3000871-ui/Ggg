#include "GggProgressionComponent.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"
UGggProgressionComponent::UGggProgressionComponent(){ SetIsReplicatedByDefault(true); }
void UGggProgressionComponent::GrantXP(int32 Amount){
 if(!GetOwner() || !GetOwner()->HasAuthority() || Amount<=0 || Level>=100) return;
 XP += FMath::Min(Amount,100000);
 while(Level<100 && XP>=Level*100){ XP-=Level*100; ++Level; }
 if(Level==100) XP=0;
}
void UGggProgressionComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& Out) const {
 Super::GetLifetimeReplicatedProps(Out);
 DOREPLIFETIME(UGggProgressionComponent,Level);
 DOREPLIFETIME(UGggProgressionComponent,XP);
}
