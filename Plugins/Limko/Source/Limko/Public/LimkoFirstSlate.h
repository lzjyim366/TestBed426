// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"


//Official Ver:

// class LIMKO_API SLimkoFirstSlate : public SCompoundWidget
// {
// public:
// 	SLATE_BEGIN_ARGS(SLimkoFirstSlate)
// 		{
// 		}
//
// 	SLATE_END_ARGS()
//
// 	/** Constructs this widget with InArgs */
// 	void Construct(const FArguments& InArgs);
// };

//PSZ Ver:
/**
 * 管理真正的Slate面板的类
 */
class SlimkoFirstSlate: public SCompoundWidget
{
	//setup stage
	SLATE_BEGIN_ARGS(SlimkoFirstSlate){}
		//SLATE_ARGUMENT(bool, bBoolFactor)
		// SLATE_ATTRIBUTE(bool,IsResTrue)
	SLATE_END_ARGS()

	//construct stage
	void Construct(const FArguments& InArgs);
	//void Construct(const FArguments& InArgs, bool bBool);
	// bool IsResTrue() const{return true;}
	
	//custom functions
	static void RequestSpawn();
};
