// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogDataAsset.h"
#include "GameData.h"
#include "SceneDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class OTW_BABYPROJECT_API USceneDataAsset : public UGameData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	FSoftObjectPath BackgroundImage;

	UPROPERTY(EditDefaultsOnly)
	TArray<FDialogueLine> DialogLines;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSoftObjectPtr<USceneDataAsset> NextScene;
};
