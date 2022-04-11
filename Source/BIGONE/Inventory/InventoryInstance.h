// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemStackInstance.h"
#include "UObject/Object.h"
#include "InventoryInstance.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class BIGONE_API UInventoryInstance : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UItemStackInstance*> Items;

	UFUNCTION(BlueprintCallable)
	void Initialize(FIntPoint Size);

	UFUNCTION(BlueprintCallable)
	bool IsEmpty() const;

	UFUNCTION(BlueprintCallable)
	int GetTotalSlotsCount() const;

	UFUNCTION(BlueprintCallable)
	int GetFreeSlotsCount() const;

	UFUNCTION(BlueprintCallable)
	int GetTakenSlotsCount() const;

	UFUNCTION(BlueprintCallable)
	bool IsSlotTaken(FIntPoint position) const;

	UItemStackInstance* GetItemAtPosition(FIntPoint position);

	UFUNCTION(BlueprintCallable)
	FIntPoint GetInventorySize() const;

	UFUNCTION(BlueprintCallable)
	bool AddItem(UItemStackInstance* item, FIntPoint position);
	
	UFUNCTION(BlueprintCallable)
	bool RemoveItemByReference(UItemStackInstance* item);

	UFUNCTION(BlueprintCallable)
	bool RemoveItemByPosition(FIntPoint position);

private:

	UPROPERTY(EditAnywhere)
	FIntPoint Size;

	TArray<int> Slots;

	int PositionToIndex(FIntPoint position) const;
	FIntPoint IndexToPosition(int index) const;
};
