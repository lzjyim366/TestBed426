// Fill out your copyright notice in the Description page of Project Settings.


#include "LimkoTestAssetTypeActions.h"

#include "LimkoTestAsset.h"
#define LOCTEXT_NAMESPACE "LimkoTest"

/**
 * 
 * @return Asset名字是LimkoTestAsset
 */
FText FLimkoTestAssetTypeActions::GetName() const
{
	  return LOCTEXT("LimkoTestTypeActions","LimkoTestAsset");
}

/**
 * 
 * @return Asset图标颜色是66ccff
 */
FColor FLimkoTestAssetTypeActions::GetTypeColor() const
{
	   return FColor(102,204,255);
}

/**
 * 
 * @return Asset的UObject是UlimkoTestAsset类型
 */
UClass* FLimkoTestAssetTypeActions::GetSupportedClass() const
{
	   return ULimkoTestAsset::StaticClass();
}

/**
 * 
 * @return Asset category
 */
uint32 FLimkoTestAssetTypeActions::GetCategories()
{
	   return  EAssetTypeCategories::Misc;
}
// TODO: 分析OpenAssetEdior调用链
//指定打开Asset编辑器后的行为
void FLimkoTestAssetTypeActions::OpenAssetEditor(const TArray<UObject*>& InObjects,
 TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
   //FAssetTypeActions_Base::OpenAssetEditor(InObjects, EditWithinLevelEditor);
    //TODO:了解Mode、IToolkitHost
    EToolkitMode::Type Mode = EToolkitMode::Standalone;
    for(auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
    {
        auto Asset = Cast<ULimkoTestAsset> (*ObjIt);
        if(Asset!=NULL)
        {
           //new一个limko asset tool
           TSharedRef<FLimkoTestAssetToolkit> NewToolkit(new FLimkoTestAssetToolkit());
           NewToolkit->Initialize(Mode,EditWithinLevelEditor,Asset);
        }
    }
}

#undef LOCTEXT_NAMESPACE
