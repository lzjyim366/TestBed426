// Fill out your copyright notice in the Description page of Project Settings.


#include "LimkoTestAssetFactory.h"

#include "AssetTypeCategories.h"
#include "LimkoTestAsset.h"

# define LOCTEXT_NAMESPACE "LimkoTest"
/**
 * 
 * @param 初始化Factory
 */
ULimkoTestAssetFactory::ULimkoTestAssetFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bCreateNew=true;
	bEditAfterNew=true;
	SupportedClass=ULimkoTestAsset::StaticClass();
}
/**
 * Factory Create New Asset
 * @param InClass 
 * @param InParent 
 * @param InName 
 * @param Flags 
 * @param Context 
 * @param Warn 
 * @return 
 */
UObject* ULimkoTestAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn)
{
	ULimkoTestAsset* CreatedAsset=NewObject<ULimkoTestAsset>(InParent, InClass, InName, Flags|RF_Transactional);
	return CreatedAsset;
}

/**
 * 
 * @return Menu Category
 */
uint32 ULimkoTestAssetFactory::GetMenuCategories() const
{
	return EAssetTypeCategories::Misc;
}
#undef LOCTEXT_NAMESPACE