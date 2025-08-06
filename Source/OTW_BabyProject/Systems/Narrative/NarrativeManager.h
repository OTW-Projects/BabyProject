// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NarrativeManager.generated.h"

/**
 * 
 */
UCLASS()
class OTW_BABYPROJECT_API UNarrativeManager : public UObject
{
	GENERATED_BODY()
	
public:
	void Initialize();

	UDataAsset* GetSpecificData(int DataAssetID) const;
	
	UDataAsset* GetDialogData(int DialogDataID) const;
};
