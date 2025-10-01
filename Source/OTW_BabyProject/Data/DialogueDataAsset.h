// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData.h"
#include "DialogueDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FDialogueLine
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString SpeakerName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString DialogueText;
};

UCLASS(BlueprintType)
class OTW_BABYPROJECT_API UDialogueDataAsset : public UGameData
{
	GENERATED_BODY()

public:


private:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Dialogue Data", meta = (AllowPrivateAccess = "true"))
	TArray<FDialogueLine> DialogueLines;

public:
	
	[[nodiscard]] TArray<FDialogueLine> GetDialogueLines() const;
};
