
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
	
	UFUNCTION()
	void HandleDialogueChanged(const FDialogueLine& NewLine);

	UFUNCTION()
	void HandleSceneChanged(const USceneDataAsset* NewScene);

private:
	void UpdateDialogueDisplay(const FDialogueLine& DialogueLine);
	
	void UpdateBackgroundDisplay(USceneDataAsset* Scene);
	
	void HandleSceneTransition(USceneDataAsset* NewScene);
};
