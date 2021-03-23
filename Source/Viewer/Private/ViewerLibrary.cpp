// Fill out your copyright notice in the Description page of Project Settings.


#include "ViewerLibrary.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Blueprint/WidgetBlueprintLibrary.h"
#include "UObject/ScriptDelegates.h"
#include "..\Public\ViewerLibrary.h"

float UViewerLibrary::ViewerSampleFunction(float Param)
{
	return 0.0f;
}

UUserWidget* UViewerLibrary::CreateWidgetInNewWindow(UClass* UMG, UObject* WorldContextObject, int ResX, int ResY, FString WindowTitle, bool SupportMinimize, bool SupportMaximize, bool SupportResize, bool AlwaysOnTop)
{
	// Check if UClass is of Class UserWidget
	if (UKismetMathLibrary::ClassIsChildOf(UMG, UUserWidget::StaticClass()))
	{
		UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
		// Todo: Create function setting the value for "IsTopmost.." depending on Play is in Engine Viewport (Otherwise there is a crash)
		// Create a new window

		UUserWidget* WidgetToCreate{};
		WidgetToCreate = UWidgetBlueprintLibrary::Create(World, UMG, ((APlayerController*)nullptr));

		auto NewWindow = SNew(SWindow)
			.Title(FText::FromString(WindowTitle))
			.UseOSWindowBorder(false)
			.ClientSize(FVector2D(ResX, ResY))
			.SupportsMinimize(SupportMinimize)
			.SupportsMaximize(SupportMaximize)
			.UserResizeBorder(SupportResize)
			.IsTopmostWindow(AlwaysOnTop)
			[
				SNew(SOverlay)
				+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			];


		FSlateApplication::Get().AddWindow(NewWindow, true);
		NewWindow->SetContent(WidgetToCreate->TakeWidget());

		return WidgetToCreate;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Selected Class was not a Widget"));
		return false;
	};
}
