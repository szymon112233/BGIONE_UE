// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemType.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, Abstract)
class BIGONE_API UItemType : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIntPoint Size;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsStackable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxStackSize = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 MaxStackSizeTest = 1;
};
