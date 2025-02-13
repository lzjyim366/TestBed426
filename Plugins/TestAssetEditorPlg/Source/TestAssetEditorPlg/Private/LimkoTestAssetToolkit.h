// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Toolkits/AssetEditorToolkit.h"
#include "LimkoTestAsset.h"
/**
 * 
 */
class  FLimkoTestAssetToolkit : public FAssetEditorToolkit
{
public:
	//Toolkit Interface Begin
	//FAssetEditorToolkit类必须继承的4个虚函数

	//正在编辑的Asset
	ULimkoTestAsset* EditingAsset;
	
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	//Toolkit Interface End

	//初始化Toolkit，在AssetTypeActions::OpenAssetEdior里面调用。
	void Initialize(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, class ULimkoTestAsset* Asset);

	//注册tab
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;

	//生成TestTab调用
	TSharedRef<SDockTab> SpawnTestTab(const FSpawnTabArgs& Args);
private:
	static const FName TestTabId;
};
