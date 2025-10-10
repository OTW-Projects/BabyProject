// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "VNGameMode.generated.h"

class UNarrativeManager;
class UUIManager;
class USceneDataAsset;

UCLASS()
class OTW_BABYPROJECT_API AVNGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	AVNGameMode();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY()
	TObjectPtr<UNarrativeManager> NarrativeManager;
	
	UPROPERTY()
	TObjectPtr<UUIManager> UIManager;

	//TEMPORARY -> Refactor later
	UPROPERTY(EditDefaultsOnly, Category = "Starting Scene")
	TSoftObjectPtr<USceneDataAsset> StartingScene;

	void InitializeGameSystems();

	void StartStory();
};
