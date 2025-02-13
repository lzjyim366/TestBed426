// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"
#include "LimkoTestAssetToolkit.h"
//
// #include "LimkoTestAssetTypeActions.generated.h"

/**
 * 需要重载父类的4个虚函数，用来描述Asset
 */
class FLimkoTestAssetTypeActions : public FAssetTypeActions_Base
{
public:
	//Asset名
	virtual FText GetName() const override;
	//Asset图标颜色
	virtual FColor GetTypeColor() const override;
	//Asset的Uobject是什么
	virtual UClass* GetSupportedClass() const override;
	//Asset所属分类
	virtual uint32 GetCategories() override;

	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor) override;
};
