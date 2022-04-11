// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryInstance.h"

void UInventoryInstance::Initialize(FIntPoint size)
{
	this->Size = size;
	Slots.AddDefaulted(GetTotalSlotsCount());
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
		if (Size[i] == -1)
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
	if (IsSlotTaken(position))
	{
		return false;
	}

	
	return false;
}


bool UInventoryInstance::RemoveItemByReference(UItemStackInstance* item)
{
	return false;
}

bool UInventoryInstance::RemoveItemByPosition(FIntPoint position)
{
	return false;
}

bool UInventoryInstance::IsSlotTaken(FIntPoint position) const
{
	return Slots[PositionToIndex(position)] != -1;
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

int UInventoryInstance::PositionToIndex(const FIntPoint position) const
{
	return position.X -1 * Size.X + position.Y -1;
}

FIntPoint UInventoryInstance::IndexToPosition(int index) const
{
	FIntPoint position;
	position.X = index/Size.X + 1;
	position.Y = index%Size.X + 1;
	return position;
}
