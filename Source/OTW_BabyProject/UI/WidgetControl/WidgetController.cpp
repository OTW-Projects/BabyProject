// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetController.h"

#include "OTW_BabyProject/Systems/Narrative/NarrativeManager.h"

void UWidgetController::Init(UNarrativeManager* InNarrativeManager)
{
	NarrativeManager = InNarrativeManager;

	if (NarrativeManager)
	{
		NarrativeManager->OnDialogueChanged.AddUObject(this, &UWidgetController::HandleDialogueChanged);
		NarrativeManager->OnSceneChanged.AddUObject(this, &UWidgetController::HandleSceneChanged);
	}
}

void UWidgetController::HandleDialogueChanged(const FDialogueLine& NewLine)
{
	
}

void UWidgetController::HandleSceneChanged(const USceneDataAsset* NewScene)
{
	
}
