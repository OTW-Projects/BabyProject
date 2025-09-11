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

	//DECLARE_MULTICAST_DELEGATE_OneParam()
	
	void Initialize();

	UDataAsset* GetSpecificData(int DataAssetID) const;
	
	UDataAsset* GetDialogData(int DialogDataID) const;

	UFUNCTION(Blueprintable)
	void LoadScene(USceneDataAsset* NewScene);

	UFUNCTION(Blueprintable)
	void LoadNextScene();

	void NextDialogue();
	
	void ResetDialogueCount();


private:

	int32 CurrentDialogueIndex = 0;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	USceneDataAsset* CurrentScene;

public:
	
	[[nodiscard]] int32 GetCurrentDialogueIndex() const;
};
