
#pragma once

#include "CoreMinimal.h"
#include "OTW_BabyProject/Data/DialogDataAsset.h"
#include "OTW_BabyProject/Data/SceneDataAsset.h"
#include "UObject/Object.h"
#include "WidgetController.generated.h"


class UNarrativeManager;
class UUIManager;

UCLASS(BLueprintable, BlueprintType)
class OTW_BABYPROJECT_API UWidgetController : public UObject
{
	GENERATED_BODY()


private:

	UPROPERTY()
	TObjectPtr<UNarrativeManager> NarrativeManager;

	UPROPERTY()
	TObjectPtr<UUIManager> UIManager;

public:
	
	UFUNCTION(BlueprintCallable)
	void Init(UNarrativeManager* InNarrativeManager, UUIManager* InUIManager);
	
	UFUNCTION(BlueprintCallable)
	void HandleDialogueChanged(const FDialogueLine& NewLine);

	UFUNCTION(BlueprintCallable)
	void HandleSceneChanged(const USceneDataAsset* NewScene);

	UFUNCTION(BlueprintCallable)
	void OnNextButtonPressed();

	UFUNCTION(BlueprintCallable)
	void ShowGameUI();

	UFUNCTION(BlueprintCallable)
	void HideGameUI();

private:
	void UpdateDialogueDisplay(const FDialogueLine& DialogueLine);
	
	void UpdateBackgroundDisplay(const USceneDataAsset* Scene);
	
	void HandleSceneTransition(const USceneDataAsset* NewScene);
};
