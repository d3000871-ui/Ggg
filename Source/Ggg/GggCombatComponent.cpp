#include "GggCombatComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

UGggCombatComponent::UGggCombatComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    SetIsReplicatedByDefault(true);
}

void UGggCombatComponent::PerformAttack()
{
    if (GetOwner() && GetOwner()->HasAuthority())
    {
        ServerPerformAttack();
    }
    else
    {
        ServerPerformAttack();
    }
}

void UGggCombatComponent::ServerPerformAttack_Implementation()
{
    AActor* OwnerActor = GetOwner();
    if (!OwnerActor || !OwnerActor->HasAuthority()) return;

    const float Now = GetWorld()->GetTimeSeconds();
    if (Now - LastAttackTime < AttackCooldown) return;
    LastAttackTime = Now;

    FVector Start;
    FRotator ViewRotation;
    OwnerActor->GetActorEyesViewPoint(Start, ViewRotation);
    const FVector End = Start + ViewRotation.Vector() * AttackRange;

    FHitResult Hit;
    FCollisionQueryParams Params(SCENE_QUERY_STAT(GggMeleeAttack), false, OwnerActor);
    if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Pawn, Params))
    {
        AActor* Target = Hit.GetActor();
        if (Target && Target != OwnerActor)
        {
            UGameplayStatics::ApplyDamage(Target, AttackDamage, OwnerActor->GetInstigatorController(), OwnerActor, nullptr);
        }
    }
}
