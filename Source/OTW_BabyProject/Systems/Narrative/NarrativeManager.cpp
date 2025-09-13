// Fill out your copyright notice in the Description page of Project Settings.


#include "NarrativeManager.h"

void UNarrativeManager::Initialize()
{
	if (CurrentScene)
	{
		LoadScene(CurrentScene);
		
		CurrentDialogue = CurrentScene->DialogLines[CurrentDialogueIndex];
	}
}

void UNarrativeManager::NextDialogue()
{
	CurrentDialogueIndex++;

	if (OnDialogueChanged.IsBound())
	{
		OnDialogueChanged.Broadcast(CurrentScene->DialogLines[CurrentDialogueIndex]);
	}
	
	if (CurrentDialogueIndex >= CurrentScene->DialogLines.Num())
	{
	    LoadNextScene();
		ResetDialogueCount();
	}

}

void UNarrativeManager::ResetDialogueCount()
{
	CurrentDialogueIndex = 0;
}

void UNarrativeManager::LoadScene(USceneDataAsset* NewScene)
{
	if (NewScene != nullptr)
	{
		CurrentScene = NewScene;
		ResetDialogueCount();

		if (OnSceneChanged.IsBound())
		{
			OnSceneChanged.Broadcast(CurrentScene->NextScene);
		}
	}
}

void UNarrativeManager::LoadNextScene()
{
	LoadScene(CurrentScene->NextScene);
}


int32 UNarrativeManager::GetCurrentDialogueIndex() const
{
	return CurrentDialogueIndex;
}
