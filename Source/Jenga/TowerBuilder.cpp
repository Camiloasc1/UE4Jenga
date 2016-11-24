// Fill out your copyright notice in the Description page of Project Settings.

#include "Jenga.h"
#include "TowerBuilder.h"
#include "JengaPiece.h"

// Sets default values
ATowerBuilder::ATowerBuilder()
{
    Height = 18;

// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATowerBuilder::BeginPlay()
{
    Super::BeginPlay();

    static FRotator rotator[2]
        { FRotator(0, 0, 0), FRotator(0, 90, 0) };
    static FVector location[2][3]
        {
            { FVector(0, -1, 0), FVector(0, 0, 0), FVector(0, 1, 0) },
            { FVector(-1, 0, 0), FVector(0, 0, 0), FVector(1, 0, 0) } };
    static AJengaPiece* piece;
    if (Piece)
    {
        int count = 0;
        for (int i = 0; i < Height; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                FVector pos = Offset * location[i % 2][j] + FVector(0, 0, i * Offset.Z);
                piece = GetWorld()->SpawnActor < AJengaPiece
                        > (Piece, pos, rotator[i % 2], FActorSpawnParameters());
                piece->SetNumber(++count);
            }
        }
    }
//    GetWorld()->SpawnActor < AJengaPiece
//            > (Piece->GeneratedClass, FVector(0, 0, 0), FRotator(0, 0, 0), FActorSpawnParameters());
}

// Called every frame
void ATowerBuilder::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

