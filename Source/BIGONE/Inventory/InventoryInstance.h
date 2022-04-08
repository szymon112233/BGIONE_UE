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
};
