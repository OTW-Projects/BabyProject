// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"

void UUIManager::Init()
{
	CreateMainGameWidget();
	
	UE_LOG(LogTemp, Log, TEXT("UIManager initialized successfully"));
}

void UUIManager::ShowDialogueUI(const FString& SpeakerName, const FString& DialogueText)
{
	if (CurrentState != EUIState::InGame)
	{
		UE_LOG(LogTemp, Warning, TEXT("UIManager: Trying to show dialogue while not in game state"));
		return;
	}

	UpdateDialogueWidget(SpeakerName, DialogueText);
}

void UUIManager::ShowSceneTransitionUI()
{
}

void UUIManager::CreateMainGameWidget()
{
	UE_LOG(LogTemp, Log, TEXT("CreateMainGameWidget called - implement widget blueprint loading here"));
}

void UUIManager::UpdateDialogueWidget(const FString& Speaker, const FString& Text)
{
	UE_LOG(LogTemp, Log, TEXT("UpdateDialogueWidget: %s says '%s'"), *Speaker, *Text);
}

void UUIManager::UpdateBackgroundWidget(const FSoftObjectPath& BackgroundPath)
{
}
