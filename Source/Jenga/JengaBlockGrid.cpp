// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Jenga.h"
#include "JengaBlockGrid.h"
#include "JengaBlock.h"
#include "Components/TextRenderComponent.h"

#define LOCTEXT_NAMESPACE "PuzzleBlockGrid"

AJengaBlockGrid::AJengaBlockGrid()
{
    // Create dummy root scene component
    DummyRoot = CreateDefaultSubobject < USceneComponent > (TEXT("Dummy0"));
    RootComponent = DummyRoot;

    // Create static mesh component
    ScoreText = CreateDefaultSubobject < UTextRenderComponent > (TEXT("ScoreText0"));
    ScoreText->SetRelativeLocation(FVector(200.f, 0.f, 0.f));
    ScoreText->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));
    ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Score: {0}"), FText::AsNumber(0)));
    ScoreText->AttachTo(DummyRoot);

    // Set defaults
    Size = 3;
    BlockSpacing = 300.f;
}

void AJengaBlockGrid::BeginPlay()
{
    Super::BeginPlay();

    // Number of blocks
    const int32 NumBlocks = Size * Size;

    // Loop to spawn each block
    for (int32 BlockIndex = 0; BlockIndex < NumBlocks; BlockIndex++)
    {
        const float XOffset = (BlockIndex / Size) * BlockSpacing; // Divide by dimension
        const float YOffset = (BlockIndex % Size) * BlockSpacing; // Modulo gives remainder

        // Make postion vector, offset from Grid location
        const FVector BlockLocation = FVector(XOffset, YOffset, 0.f) + GetActorLocation();

        // Spawn a block
        AJengaBlock* NewBlock = GetWorld()->SpawnActor < AJengaBlock
                > (BlockLocation, FRotator(0, 0, 0));

        // Tell the block about its owner
        if (NewBlock != NULL)
        {
            NewBlock->OwningGrid = this;
        }
    }
}

void AJengaBlockGrid::AddScore()
{
    // Increment score
    Score++;

    // Update text
    ScoreText->SetText(
            FText::Format(LOCTEXT("ScoreFmt", "Score: {0}"), FText::AsNumber(Score)));
}

#undef LOCTEXT_NAMESPACE
