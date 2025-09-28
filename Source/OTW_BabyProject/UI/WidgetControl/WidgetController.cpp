// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetController.h"

#include "OTW_BabyProject/Systems/Narrative/NarrativeManager.h"
#include "OTW_BabyProject/UI/UIManager.h"

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
	UpdateDialogueDisplay(NewLine);
}

void UWidgetController::HandleSceneChanged(const USceneDataAsset* NewScene)
{
	if (!NewScene)
	{
		UE_LOG(LogTemp, Error, TEXT("WidgetController: New scene is NULL"));
		return;
	}

	HandleSceneChanged(NewScene);
	UpdateBackgroundDisplay(NewScene);
}

void UWidgetController::OnNextButtonPressed()
{
	if (NarrativeManager)
	{
		NarrativeManager->NextDialogue();
	}
}

void UWidgetController::ShowGameUI()
{
	if (UIManager)
	{
		UIManager->ShowGameUI();

		if (NarrativeManager)
		{
			//FDialogueLine CurrentDialogueLine = NarrativeManager->
		}
	}
}

void UWidgetController::HideGameUI()
{
	if (UIManager)
	{
		UIManager->HideGameUI();
	}
}

void UWidgetController::UpdateDialogueDisplay(const FDialogueLine& DialogueLine)
{
	if (UIManager)
	{
		UIManager->ShowDialogueUI(DialogueLine.SpeakerName, DialogueLine.DialogueText);
	}
}

void UWidgetController::UpdateBackgroundDisplay(const USceneDataAsset* Scene)
{
	if (UIManager && Scene)
	{
		UIManager->SetBackground(Scene->BackgroundImage);
	}
}

void UWidgetController::HandleSceneTransition(const USceneDataAsset* NewScene)
{
	//UE_LOG(LogTemp, Log, TEXT("Transitioning to scene: %s"), NewScene ? NewScene->GetName() : TEXT("Unknown"));
}
