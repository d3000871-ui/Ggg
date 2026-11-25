#include "GggInventoryComponent.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"

UGggInventoryComponent::UGggInventoryComponent()
{
    SetIsReplicatedByDefault(true);
}

void UGggInventoryComponent::AddItem(FName ItemId, int32 Quantity)
{
    if (ItemId.IsNone() || Quantity <= 0) return;
    ServerAddItem(ItemId, Quantity);
}

void UGggInventoryComponent::RemoveItem(FName ItemId, int32 Quantity)
{
    if (ItemId.IsNone() || Quantity <= 0) return;
    ServerRemoveItem(ItemId, Quantity);
}

void UGggInventoryComponent::ServerAddItem_Implementation(FName ItemId, int32 Quantity)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || ItemId.IsNone() || Quantity <= 0) return;

    for (FGggItemStack& Stack : Items)
    {
        if (Stack.ItemId == ItemId)
        {
            Stack.Quantity += Quantity;
            OnRep_Items();
            return;
        }
    }

    if (Items.Num() < MaxSlots)
    {
        FGggItemStack NewStack;
        NewStack.ItemId = ItemId;
        NewStack.Quantity = Quantity;
        Items.Add(NewStack);
        OnRep_Items();
    }
}

void UGggInventoryComponent::ServerRemoveItem_Implementation(FName ItemId, int32 Quantity)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || Quantity <= 0) return;

    for (int32 Index = Items.Num() - 1; Index >= 0; --Index)
    {
        if (Items[Index].ItemId == ItemId)
        {
            Items[Index].Quantity = FMath::Max(0, Items[Index].Quantity - Quantity);
            if (Items[Index].Quantity == 0) Items.RemoveAt(Index);
            OnRep_Items();
            return;
        }
    }
}

int32 UGggInventoryComponent::GetItemQuantity(FName ItemId) const
{
    for (const FGggItemStack& Stack : Items)
    {
        if (Stack.ItemId == ItemId) return Stack.Quantity;
    }
    return 0;
}

void UGggInventoryComponent::OnRep_Items()
{
    // Override or bind UI refresh logic in a Blueprint subclass.
}

void UGggInventoryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(UGggInventoryComponent, Items);
}
