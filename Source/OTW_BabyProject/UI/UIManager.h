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
	void ShowSceneTransitionUI();

private:

	void CreateMainGameWidget();

	void UpdateDialogueWidget(const FString& Speaker, const FString& Text);

	void UpdateBackgroundWidget(const FSoftObjectPath& BackgroundPath);
};
