// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LimkoTestAsset.generated.h"

/**
 * 
 */
UCLASS(EditInlineNew, config=Engine)
// class TESTASSETEDITORPLG_API ULimkoTestAsset : public UObject
// {
// 	GENERATED_BODY()
// };
class  ULimkoTestAsset : public UObject
{
	GENERATED_UCLASS_BODY()
public:
		UPROPERTY(EditAnywhere)
		int TestData;
};