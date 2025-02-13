// Fill out your copyright notice in the Description page of Project Settings.


#include "LimkoTestAssetToolkit.h"

#define LOCTEXT_NAMESPACE "LimkoTest"

//指定Tab的ID
const FName FLimkoTestAssetToolkit::TestTabId(TEXT("LimkoTestAssetEditor_TestTab"));

FName FLimkoTestAssetToolkit::GetToolkitFName() const
{
	return FName("lIMKOTestAssetName");
}

FText FLimkoTestAssetToolkit::GetBaseToolkitName() const
{
	//TODO: 重新理解LOCTEXT
	return  LOCTEXT("LimkoTestAssetLable","LimkoTestAssetBase");
}

FString FLimkoTestAssetToolkit::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("LimkoTestAssetTablePrefix","LimkoTestAssetPrefix").ToString();
}

FLinearColor FLimkoTestAssetToolkit::GetWorldCentricTabColorScale() const
{
	return FLinearColor(.4f,.8f,1.0f);
}

//TODO: 看一下Register
//注册Tab，即，把TabID和SpawnTestTab中Tab的实质内容联系起来
void FLimkoTestAssetToolkit::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	//注意TabManger是AssetEditorToolkit里面已有的变量，别把参数命名为TabManager,不然编译过不了
	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);
	InTabManager->RegisterTabSpawner(TestTabId,FOnSpawnTab::CreateSP(this,&FLimkoTestAssetToolkit::SpawnTestTab))
		.SetDisplayName(LOCTEXT("LimkoTestAssetTestTab","LimkoTestAssetTestTab"));
}

//设定将要弹出的Tab里面有些什么内容。
TSharedRef<SDockTab> FLimkoTestAssetToolkit::SpawnTestTab(const FSpawnTabArgs& Args)
{
	//TODO: 看一下SDockTab
	return
		SNew(SDockTab)
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			.AutoHeight()
			[
				//Tab里面的内容就是一个按钮
				SNew(STextBlock)
				.Text(FText::FromString("How many times did Limko meow: "+FString::FromInt(EditingAsset->TestData)))
			]
			+SVerticalBox::Slot()
			.AutoHeight()
			[
				//Tab里面的内容就是一个按钮
				SNew(SButton)
				.Text(FText::FromString("LimkooooMeowww"))
				.OnClicked_Lambda([this]()
				{
					EditingAsset->TestData++;
					return FReply::Handled();
				})
			]
		];
}
//在Layout中添加Tab，并且把这个Laout赋给我们的Asset菜单
void FLimkoTestAssetToolkit::Initialize(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost,
	ULimkoTestAsset* Asset)
{
	EditingAsset=Asset;
	TSharedRef<FTabManager::FLayout> Layout=FTabManager::NewLayout("LimkoTestAssetEditor_Layout")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewSplitter()->SetOrientation(Orient_Horizontal)->SetSizeCoefficient(0.9f)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(.7f)
					->AddTab(TestTabId,ETabState::OpenedTab)
				)
			)
		);
	const bool bCreateDefaultStandaloneMenu=true;
	const bool bCreateDefaultToolbar=true;
	const FName AppIdentifier = TEXT("LimkoTestAssetEditor");
	//FAssetEditorToolkit::InitAssetEditor(Mode, InitToolkitHost, AppIdentifier, Layout, bCreateDefaultStandaloneMenu, bCreateDefaultToolbar, Asset);

	//核心函数
	FAssetEditorToolkit::InitAssetEditor(Mode,InitToolkitHost, AppIdentifier, Layout, bCreateDefaultStandaloneMenu, bCreateDefaultToolbar, Asset);
}
#undef LOCTEXT_NAMESPACE
