// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LimkoFirstSlate.h"
#include "LimkoBP.generated.h"


/**
 * 管理BP接口的类
 * 没什么实质功能，除了会调用Slate的构造函数
 */
UCLASS()
class LIMKO_API ULimkoBP : public UObject
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable)
	static void SpawnMainWindow();
};
