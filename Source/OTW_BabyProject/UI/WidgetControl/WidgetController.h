
#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "OTW_BabyProject/Data/DialogDataAsset.h"
#include "OTW_BabyProject/Data/SceneDataAsset.h"
#include "UObject/Object.h"
#include "WidgetController.generated.h"

/**
 * 
 */
UCLASS(BLueprintable, BlueprintType)
class OTW_BABYPROJECT_API UWidgetController : public UObject
{
	GENERATED_BODY()

public:

	void Init(class UNarrativeManager* InNarrativeManager);

private:

	UPROPERTY()
	UNarrativeManager* NarrativeManager;

	UFUNCTION()
	void HandleDialogueChanged(const FDialogueLine& NewLine);

	UFUNCTION()
	void HandleSceneChanged(const USceneDataAsset* NewScene);
};
