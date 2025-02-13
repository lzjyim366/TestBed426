// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestAssetEditorPlg.h"
#include "AssetToolsModule.h"
#include "LimkoTestAssetTypeActions.h"
#define LOCTEXT_NAMESPACE "FTestAssetEditorPlgModule"

void FTestAssetEditorPlgModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	IAssetTools& AssetTools=FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	//注册我们自定义的AssetTypeActions
	AssetTools.RegisterAssetTypeActions(MakeShareable(new FLimkoTestAssetTypeActions()));
	//UFactory不用注册，可能是因为继承自UObject自动拥有反射
}

void FTestAssetEditorPlgModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTestAssetEditorPlgModule, TestAssetEditorPlg)