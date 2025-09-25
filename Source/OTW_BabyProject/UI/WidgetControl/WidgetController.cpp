// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetController.h"

#include "OTW_BabyProject/Systems/Narrative/NarrativeManager.h"

void UWidgetController::Init(UNarrativeManager* InNarrativeManager, UUIManager* InUIManager)
{
	if (!InNarrativeManager || !InUIManager)
	{
		UE_LOG(LogTemp, Error, TEXT("WidgetController: Invalid managers passed to Initialize"));
		return;
	}

	NarrativeManager = InNarrativeManager;
	UIManager = InUIManager;

	NarrativeManager->OnDialogueChanged.AddUObject(this, &UWidgetController::HandleDialogueChanged);
	NarrativeManager->OnSceneChanged.AddUObject(this, &UWidgetController::HandleSceneChanged);

	UE_LOG(LogTemp, Log, TEXT("WidgetController initialized successfully"));
}

void UWidgetController::HandleDialogueChanged(const FDialogueLine& NewLine)
{
}

void UWidgetController::HandleSceneChanged(const USceneDataAsset* NewScene)
{
}

void UWidgetController::UpdateDialogueDisplay(const FDialogueLine& DialogueLine)
{
}

void UWidgetController::UpdateBackgroundDisplay(USceneDataAsset* Scene)
{
}

void UWidgetController::HandleSceneTransition(USceneDataAsset* NewScene)
{
}
