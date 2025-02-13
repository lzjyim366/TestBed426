// Fill out your copyright notice in the Description page of Project Settings.


#include "LimkoFirstSlate.h"

#include "SlateOptMacros.h"
#include "Misc/MessageDialog.h"
#include "Widgets/Input/SEditableText.h"
#include "Widgets/Text/SInlineEditableTextBlock.h"

#define LOCTEXT_NAMESPACE "Limko"
// BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

// void SLimkoFirstSlate::Construct(const FArguments& InArgs)
// {
// 	/*
// 	ChildSlot
// 	[
// 		// Populate the widget
// 	];
// 	*/
// }
void SlimkoFirstSlate::Construct(const FArguments& InArgs)
{
	//bool bBoolFactor=InArgs._bBoolFactor;
	static FText UserName;
	static FText UserPW;

	ChildSlot
	[
		SNew(SHorizontalBox)
		+SHorizontalBox::Slot()
		.FillWidth(1)
		[
			SNew(SVerticalBox)//Name
			+SVerticalBox::Slot()
			.FillHeight(1)
			.VAlign(VAlign_Center)
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				.FillWidth(.3)
				[
					SNew(STextBlock)
					.Text(FText::FromString("Name"))
				]
				+SHorizontalBox::Slot()
				.FillWidth(1)
				[
					SNew(SInlineEditableTextBlock)
					.Text(FText::FromString("username"))
					.OnTextCommitted_Lambda([this](const FText& InText, ETextCommit::Type TextCommitType)
					{
						UserName=InText;
					})
					.Text_Lambda([this]()
					{
						return UserName;
					})
				]
			]
			+SVerticalBox::Slot()//PW
			.FillHeight(1)
			.VAlign(VAlign_Center)
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				.FillWidth(.3)
				[
					SNew(STextBlock)
					.Text(FText::FromString("PW"))
				]
				+SHorizontalBox::Slot()
				.FillWidth(1)
				[
					// SNew(STextBlock)
					// .Text(FText::FromString("TextField"))
					SNew(SEditableText)
					.Text(FText::FromString("PW"))
					.OnTextCommitted_Lambda([this](const FText& InText, ETextCommit::Type TextCommitType)
					{
						UserPW=InText;
					})
					.Text_Lambda([this]()
					{
						return UserPW;
					})
				]
			]
			+SVerticalBox::Slot()//Btn
			.FillHeight(1)
			.VAlign(VAlign_Center)
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				.FillWidth(1)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Limko",""))
				]
				+SHorizontalBox::Slot()
				.FillWidth(.3)
				[
					
					SNew(SButton)
					.OnClicked_Lambda([]()
					{
						// UserName == ZJY
						// Password == PSZ
						if(UserName.EqualTo(FText::FromString("ZJY")) && UserPW.EqualTo(FText::FromString("PSZ")))
							FMessageDialog::Debugf(FText::FromString("ZZL queshi shabi"));
						return FReply::Handled();
					})
					.ContentPadding(0.0f)
					.ToolTipText(LOCTEXT("UnhideTabWellToolTip", "Confirm"))
					[
						SNew(STextBlock)
						.Text(FText::FromString("ENTER"))
					]
				]
			]
		]	
	];
}

void SlimkoFirstSlate::RequestSpawn()
{
	TSharedRef<SWindow> Window = SNew(SWindow)
	.MinWidth(300)
	.MinHeight(300)
	[
		//SNew(SlimkoFirstSlate, true)
		//.bBoolFactor(true)
		//.IsShit_Lambda([](){return true;})
		SNew(SlimkoFirstSlate)
	];

	FSlateApplication::Get().AddWindow(Window);
	//
	// GEditor->EditorAddModalWindow(Window);
}

// END_SLATE_FUNCTION_BUILD_OPTIMIZATION
#undef LOCTEXT_NAMESPACE