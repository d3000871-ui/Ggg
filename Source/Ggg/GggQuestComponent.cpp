#include "GggQuestComponent.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"
UGggQuestComponent::UGggQuestComponent(){SetIsReplicatedByDefault(true);}
void UGggQuestComponent::StartQuest(FName Id,int32 Goal){
 if(!GetOwner() || !GetOwner()->HasAuthority() || Id.IsNone() || Goal<1 || Quests.Num()>=100) return;
 for(const auto& Q:Quests) if(Q.Id==Id) return;
 FGggQuestState Q; Q.Id=Id; Q.Goal=Goal; Quests.Add(Q);
}
void UGggQuestComponent::AdvanceQuest(FName Id){
 if(!GetOwner() || !GetOwner()->HasAuthority()) return;
 for(auto& Q:Quests) if(Q.Id==Id && Q.Progress<Q.Goal) ++Q.Progress;
}
void UGggQuestComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& Out) const{
 Super::GetLifetimeReplicatedProps(Out); DOREPLIFETIME_CONDITION(UGggQuestComponent,Quests,COND_OwnerOnly);
}
