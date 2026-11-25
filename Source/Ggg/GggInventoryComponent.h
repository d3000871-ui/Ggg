#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GggInventoryComponent.generated.h"

USTRUCT(BlueprintType)
struct FGggItemStack
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName ItemId = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Quantity = 0;
};

UCLASS(ClassGroup=(Gameplay), meta=(BlueprintSpawnableComponent))
class UGggInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UGggInventoryComponent();

    UFUNCTION(BlueprintCallable, Category="Inventory")
    void AddItem(FName ItemId, int32 Quantity);

    UFUNCTION(BlueprintCallable, Category="Inventory")
    void RemoveItem(FName ItemId, int32 Quantity);

    UFUNCTION(BlueprintPure, Category="Inventory")
    int32 GetItemQuantity(FName ItemId) const;

    const TArray<FGggItemStack>& GetItems() const { return Items; }

protected:
    UFUNCTION(Server, Reliable)
    void ServerAddItem(FName ItemId, int32 Quantity);

    UFUNCTION(Server, Reliable)
    void ServerRemoveItem(FName ItemId, int32 Quantity);

    UFUNCTION()
    void OnRep_Items();

    UPROPERTY(ReplicatedUsing=OnRep_Items, VisibleAnywhere, Category="Inventory")
    TArray<FGggItemStack> Items;

    UPROPERTY(EditDefaultsOnly, Category="Inventory")
    int32 MaxSlots = 30;
};
