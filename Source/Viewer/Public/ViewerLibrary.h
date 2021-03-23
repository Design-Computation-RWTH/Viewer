// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ViewerLibrary.generated.h"

class UObject;
class UClass;
class UUserWidget;

UCLASS()
class VIEWER_API UViewerLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Sample Function", Keywords = "ViewerExtensions sample test testing"), Category = "Viewer Extensions")
	static float ViewerSampleFunction(float Param);

	UFUNCTION(BlueprintCallable, Category = "Viewer ", meta = (WorldContext = WorldContextObject))
	static UUserWidget* CreateWidgetInNewWindow(UClass* UMG, UObject* WorldContextObject, int ResX, int ResY, FString WindowTitle, bool SupportMinimize,
		bool SupportMaximize, bool SupportResize, bool AlwaysOnTop);

};
