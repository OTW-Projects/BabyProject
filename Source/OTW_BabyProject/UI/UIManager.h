// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WidgetControl/WidgetController.h"
#include "UIManager.generated.h"

class UUserWidget;

UENUM(BlueprintType)
enum class EUIState : uint8
{
	Hidden,
	MainMenu,
	InGame,
	Paused,
	Loading
};

UCLASS(Blueprintable, BlueprintType)
class OTW_BABYPROJECT_API UUIManager : public UObject
{
	GENERATED_BODY()

private:

	UPROPERTY()
	TObjectPtr<UUserWidget> MainGameWidget;
	
	UPROPERTY()
	EUIState CurrentState = EUIState::Hidden;
	
public:

	UFUNCTION(BlueprintCallable)
	void Init();

	UFUNCTION(BlueprintCallable)
	void ShowDialogueUI(const FString& SpeakerName, const FString& DialogueText);

	UFUNCTION(BlueprintCallable)
	void SetBackground(const FSoftObjectPath& BackgroundImagePath);

	UFUNCTION(BlueprintCallable)
	void ShowGameUI();

	UFUNCTION(BlueprintCallable)
	void HideGameUI();

	UFUNCTION(BlueprintCallable)
	void SetUIState(EUIState NewState);
	
	UFUNCTION(BlueprintCallable)
	void ShowSceneTransitionUI();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnDialogueChanged(const FString& Speaker, const FString& Text);
	
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnBackgroundChanged(const FSoftObjectPath& BackgroundImagePath);
	
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnUIStateChanged(EUIState NewState);

private:

	void CreateMainGameWidget();

	void UpdateDialogueWidget(const FString& Speaker, const FString& Text);

	void UpdateBackgroundWidget(const FSoftObjectPath& BackgroundPath);
};
