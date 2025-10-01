// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueDataAsset.h"

TArray<FDialogueLine> UDialogueDataAsset::GetDialogueLines() const
{
	return DialogueLines;
}
