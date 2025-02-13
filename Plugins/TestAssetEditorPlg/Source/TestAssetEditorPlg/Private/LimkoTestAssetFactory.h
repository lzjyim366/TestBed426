// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "LimkoTestAssetFactory.generated.h"

/**
 * 
 */
UCLASS(Config=Editor)
// class TESTASSETEDITORPLG_API ULimkoTestAssetFactory : public UFactory
// {
// 	GENERATED_BODY()
// };
class ULimkoTestAssetFactory: public UFactory
{
    GENERATED_UCLASS_BODY()
public:
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual uint32 GetMenuCategories() const override;
};