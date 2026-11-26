#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GggQuestComponent.generated.h"
USTRUCT(BlueprintType)
struct FGggQuestState {
 GENERATED_BODY()
 UPROPERTY(BlueprintReadOnly) FName Id = NAME_None;
 UPROPERTY(BlueprintReadOnly) int32 Goal = 1;
 UPROPERTY(BlueprintReadOnly) int32 Progress = 0;
};
UCLASS(ClassGroup=(Gameplay), meta=(BlueprintSpawnableComponent))
class UGggQuestComponent : public UActorComponent {
 GENERATED_BODY()
public:
 UGggQuestComponent();
 UPROPERTY(Replicated, BlueprintReadOnly) TArray<FGggQuestState> Quests;
 UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly) void StartQuest(FName Id,int32 Goal);
 UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly) void AdvanceQuest(FName Id);
 virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& Out) const override;
};
