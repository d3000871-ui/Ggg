#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GggProgressionComponent.generated.h"

UCLASS(ClassGroup=(Gameplay), meta=(BlueprintSpawnableComponent))
class UGggProgressionComponent : public UActorComponent
{
 GENERATED_BODY()
public:
 UGggProgressionComponent();
 UPROPERTY(Replicated, BlueprintReadOnly) int32 Level = 1;
 UPROPERTY(Replicated, BlueprintReadOnly) int32 XP = 0;
 UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly) void GrantXP(int32 Amount);
 virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& Out) const override;
};
