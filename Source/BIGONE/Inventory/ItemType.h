// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemType.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class BIGONE_API UItemType : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FIntPoint Size;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture* Icon;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsStackable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int MaxStackSize = 1;
};
