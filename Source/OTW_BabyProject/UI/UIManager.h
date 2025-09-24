// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WidgetControl/WidgetController.h"
#include "UIManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class OTW_BABYPROJECT_API UUIManager : public UObject
{
	GENERATED_BODY()

public:

	void Init(class UNarrativeManager* InNarrativeManager);

	UFUNCTION(BlueprintCallable)
	void ShowDialogueUI();
	
	UFUNCTION(BlueprintCallable)
	void ShowSceneTransitionUI();

protected:

	UPROPERTY()
	UNarrativeManager* NarrativeManager;
	
	UPROPERTY()
	UWidgetController* WidgetController;
	
	UPROPERTY()
	UUserWidget* DialogueWidgetInstance;
};
