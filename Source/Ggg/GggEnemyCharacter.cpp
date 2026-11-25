#include "GggEnemyCharacter.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/CharacterMovementComponent.h"

AGggEnemyCharacter::AGggEnemyCharacter()
{
    PrimaryActorTick.bCanEverTick = false;
    bReplicates = true;
    GetCharacterMovement()->MaxWalkSpeed = 250.0f;
}

float AGggEnemyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
    AController* EventInstigator, AActor* DamageCauser)
{
    if (!HasAuthority() || DamageAmount <= 0.0f || Health <= 0.0f) return 0.0f;

    const float AppliedDamage = FMath::Min(Health, DamageAmount);
    Health = FMath::Clamp(Health - AppliedDamage, 0.0f, MaxHealth);
    OnRep_Health();

    if (Health <= 0.0f)
    {
        SetLifeSpan(2.0f);
    }
    return AppliedDamage;
}

void AGggEnemyCharacter::OnRep_Health()
{
    // Update health bar UI in a Blueprint subclass.
}

void AGggEnemyCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(AGggEnemyCharacter, Health);
}
