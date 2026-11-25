#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GggCombatComponent.generated.h"

UCLASS(ClassGroup=(Gameplay), meta=(BlueprintSpawnableComponent))
class UGggCombatComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UGggCombatComponent();

    UFUNCTION(BlueprintCallable, Category="Combat")
    void PerformAttack();

protected:
    UFUNCTION(Server, Reliable)
    void ServerPerformAttack();

    UPROPERTY(EditDefaultsOnly, Category="Combat")
    float AttackRange = 250.0f;

    UPROPERTY(EditDefaultsOnly, Category="Combat")
    float AttackDamage = 25.0f;

    UPROPERTY(EditDefaultsOnly, Category="Combat")
    float AttackCooldown = 0.8f;

    float LastAttackTime = -1000.0f;
};
