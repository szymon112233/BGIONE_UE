// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryInstance.h"

void UInventoryInstance::Initialize(FIntPoint size, FString Name)
{
	this->Size = size;
	for (int i = 0; i < GetTotalSlotsCount(); ++i)
	{
		Slots.Add(-1);
	}
}

bool UInventoryInstance::IsEmpty() const
{
	return Items.Num() == 0; 
}

int UInventoryInstance::GetTotalSlotsCount() const
{
	return Size.X * Size.Y;
}

int UInventoryInstance::GetFreeSlotsCount() const
{
	int count = 0;
	for (int i = 0; i < Slots.Num(); ++i)
	{
		if (Slots[i] == -1)
		{
			count++;
		}
	}
	
	return count;
}

int UInventoryInstance::GetTakenSlotsCount() const
{
	return GetTotalSlotsCount() - GetFreeSlotsCount();
}

FIntPoint UInventoryInstance::GetInventorySize() const
{
	return Size;
}

bool UInventoryInstance::AddItem(UItemStackInstance* item, FIntPoint position)
{
	if (IsSpaceTaken(position, item->ItemType->Size))
	{
		return false;
	}

	int index = Items.Add(item);
	SetSlotsIndex(position, item->ItemType->Size, index);
	
	return true;
}

bool UInventoryInstance::IsSpaceTaken(FIntPoint position, FIntPoint size)
{
	for (int i = 0; i < size.X; ++i)
	{
		for (int j = 0; j < size.Y; ++j)
		{
			FIntPoint pointToCheck = position + FIntPoint(i,j); 
			if (IsSlotTaken(pointToCheck))
			{
				return true;
			}
		}
	}

	return false;
}


bool UInventoryInstance::RemoveItemByReference(UItemStackInstance* item)
{
	if (!Items.Contains(item))
	{
		return false;
	}
	
	SetSlotsIndex(GetFirstSlot(Items.Find(item)), item->ItemType->Size, EMPTY_SLOT_INDEX);
	Items.Remove(item);
	
	return true;
}

bool UInventoryInstance::RemoveItemByPosition(FIntPoint position)
{
	if (!IsSlotTaken(position))
	{
		return false;
	}
	
	int index = PositionToIndex(position);
	UItemStackInstance* item = Items[index];

	SetSlotsIndex(position, item->ItemType->Size, EMPTY_SLOT_INDEX);
	Items.RemoveAt(index);
	
	return true;
}

bool UInventoryInstance::IsSlotTaken(FIntPoint position) const
{
	return Slots[PositionToIndex(position)] != EMPTY_SLOT_INDEX;
}

UItemStackInstance* UInventoryInstance::GetItemAtPosition(FIntPoint position)
{
	if (IsSlotTaken(position))
	{
		return Items[Slots[PositionToIndex(position)]];
	}
	else
	{
		return nullptr;
	}
}

bool UInventoryInstance::SetSlotsIndex(FIntPoint position, FIntPoint size, int index)
{
	for (int i = 0; i < size.X; ++i)
	{
		for (int j = 0; j < size.Y; ++j)
		{
			FIntPoint pointToCheck = position + FIntPoint(i,j);
			Slots[PositionToIndex(pointToCheck)] = index;
		}
	}

	return true;
}

FIntPoint UInventoryInstance::GetFirstSlot(int index)
{
	for (int i = 0; i < Slots.Num(); ++i)
	{
		if (Slots[i] == index)
		{
			return IndexToPosition(i);
		}
	}

	return FIntPoint();
}

int UInventoryInstance::PositionToIndex(const FIntPoint position) const
{
	return position.X * Size.X + position.Y;
}

FIntPoint UInventoryInstance::IndexToPosition(int index) const
{
	FIntPoint position;
	position.X = index/Size.X;
	position.Y = index%Size.X;
	return position;
}
