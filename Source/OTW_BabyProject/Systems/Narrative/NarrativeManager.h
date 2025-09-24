// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OTW_BabyProject/Data/SceneDataAsset.h"
#include "NarrativeManager.generated.h"

/**
 * 
 */
UCLASS()
class OTW_BABYPROJECT_API UNarrativeManager : public UObject
{
	GENERATED_BODY()
	
public:

	DECLARE_MULTICAST_DELEGATE_OneParam(FOnDialogueChanged, const FDialogueLine&, NewDialogueLine);
	DECLARE_MULTICAST_DELEGATE_OneParam(FOnSceneChanged, const USceneDataAsset*, NewScene);

	FOnDialogueChanged OnDialogueChanged;

	FOnSceneChanged OnSceneChanged;
	
	void Initialize();
	
	UFUNCTION(Blueprintable)
	void LoadScene(USceneDataAsset* NewScene);

	UFUNCTION(Blueprintable)
	void LoadNextScene();

	//UFUNCTION(BlueprintCallable)
	void NextDialogue();
	
	void ResetDialogueCount();


private:

	int32 CurrentDialogueIndex = 0;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	USceneDataAsset* CurrentScene;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	FDialogueLine CurrentDialogue;

public:
	
	[[nodiscard]] int32 GetCurrentDialogueIndex() const;
};
