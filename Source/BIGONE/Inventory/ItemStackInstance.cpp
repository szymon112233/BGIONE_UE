// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemStackInstance.h"


int UItemStackInstance::AddItems(int count)
{
	if (!ItemType->IsStackable)
	{
		return count;
	}
		
	int afterAdd = Count + count;
		
	if (afterAdd > ItemType->MaxStackSize)
	{
		Count = ItemType->MaxStackSize;
	}
	else
	{
		Count = afterAdd;
	}
		
	return afterAdd - Count;
}

int UItemStackInstance::RemoveItems(int count)
{
	int afterRemove = Count - count;
		
	if (afterRemove < 0)
	{
		Count = 0;
		return -afterRemove;
	}
	else if (afterRemove == 0)
	{
		Count = 0;
		return 0;
	}
	else
	{
		Count = afterRemove;
		return 0;
	}
}

