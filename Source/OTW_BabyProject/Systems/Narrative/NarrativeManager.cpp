// Fill out your copyright notice in the Description page of Project Settings.


#include "NarrativeManager.h"

void UNarrativeManager::Initialize()
{
	throw std::logic_error("The method or operation is not implemented.");
}

UDataAsset* UNarrativeManager::GetSpecificData(int DataAssetID) const
{
	return NULL;
}

UDataAsset* UNarrativeManager::GetDialogData(int DialogDataID) const
{
	return NULL;
}

void UNarrativeManager::NextDialogue()
{
	CurrentDialogueIndex++;
	if (CurrentDialogueIndex >= CurrentScene->DialogLines.Num())
	{
		
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

		// if (OnSceneChanged.IsBound())
		// {
		// 	
		// }
	}
}

void UNarrativeManager::LoadNextScene()
{
}


int32 UNarrativeManager::GetCurrentDialogueIndex() const
{
	return CurrentDialogueIndex;
}
