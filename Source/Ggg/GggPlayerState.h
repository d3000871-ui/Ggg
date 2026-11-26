#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "GggPlayerState.generated.h"

UCLASS()
class GGG_API AGggPlayerState : public APlayerState
{
    GENERATED_BODY()
public:
    UPROPERTY(Replicated, BlueprintReadOnly, Category="Progression")
    int32 HunterLevel = 1;
    UPROPERTY(Replicated, BlueprintReadOnly, Category="Progression")
    int32 Experience = 0;
    UPROPERTY(Replicated, BlueprintReadOnly, Category="Progression")
    int32 Gold = 0;
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Progression")
    void GrantReward(int32 XP, int32 Coins);
    UFUNCTION(BlueprintPure, Category="Progression")
    FString GetHunterRank() const;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
