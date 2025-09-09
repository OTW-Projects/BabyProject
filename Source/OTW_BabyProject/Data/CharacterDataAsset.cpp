#include "CharacterDataAsset.h"
<<<<<<< Updated upstream
=======

const FPrimaryAssetType UCharacterDataAsset::CharacterAssetType = TEXT("CharacterDataAsset");

FPrimaryAssetId UCharacterDataAsset::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(CharacterAssetType, GetFName());
}
>>>>>>> Stashed changes
