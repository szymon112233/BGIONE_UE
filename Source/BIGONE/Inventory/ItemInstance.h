// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemType.h"
#include "UObject/Object.h"
#include "ItemInstance.generated.h"

/**
 * 
 */
UCLASS()
class BIGONE_API UItemInstance : public UObject
{
	GENERATED_BODY()

public:
	void SetType(TSubclassOf<UItemType> type)
	{
		this->Type = type;
	}

	FString GetName() const
	{
		const auto CDO = Type.GetDefaultObject();
		return CDO->Name;
	}

private:
	UPROPERTY()
	TSubclassOf<UItemType> Type;

	uint8 Count;
};
