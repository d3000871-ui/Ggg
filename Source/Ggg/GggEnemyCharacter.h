#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GggEnemyCharacter.generated.h"

UCLASS()
class AGggEnemyCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AGggEnemyCharacter();

    UFUNCTION(BlueprintCallable, Category="Enemy")
    float GetHealth() const { return Health; }

protected:
    virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
        AController* EventInstigator, AActor* DamageCauser) override;

    UFUNCTION()
    void OnRep_Health();

    UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_Health, Category="Enemy")
    float Health = 100.0f;

    UPROPERTY(EditDefaultsOnly, Category="Enemy")
    float MaxHealth = 100.0f;
};
