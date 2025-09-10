#include "CharacterDataAsset.h"

const FPrimaryAssetType UCharacterDataAsset::CharacterAssetType = TEXT("CharacterDataAsset");

FPrimaryAssetId UCharacterDataAsset::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(CharacterAssetType, GetFName());
}