// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TowerBuilder.generated.h"

UCLASS()
class JENGA_API ATowerBuilder : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ATowerBuilder();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Called every frame
    virtual void Tick( float DeltaSeconds ) override;

public:

    UPROPERTY(Category = Builder, EditAnywhere, BlueprintReadWrite)
    TSubclassOf<class AJengaPiece> Piece;

    UPROPERTY(Category = Builder, EditAnywhere, BlueprintReadWrite)
    FVector Start;

    UPROPERTY(Category = Builder, EditAnywhere, BlueprintReadWrite)
    FVector Offset;

    UPROPERTY(Category = Builder, EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0"))
    int32 Height;
};
