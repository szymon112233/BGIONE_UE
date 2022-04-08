// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemType.h"
#include "UObject/Object.h"
#include "ItemStackInstance.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class BIGONE_API UItemStackInstance : public UObject
{
	GENERATED_BODY()

public:
	void SetItemType(UItemType* type)
	{
		this->ItemType = type;
	}

	FString GetItemName() const
	{
		return ItemType->Name;
	}

	UFUNCTION(BlueprintCallable)
	void Initialise(UItemType* type, int count)
	{
		this->ItemType = type;
		this->Count = count;
	}

	UFUNCTION(BlueprintCallable)
	int AddItems(int count);

	UFUNCTION(BlueprintCallable)
	int RemoveItems(int count);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UItemType* ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 Count;
};
