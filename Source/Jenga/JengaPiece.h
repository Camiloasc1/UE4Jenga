// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "JengaPiece.generated.h"

UCLASS()
class JENGA_API AJengaPiece: public AActor
{
    GENERATED_BODY()

    /** StaticMesh for the block */
    UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    class UStaticMeshComponent* BlockMesh;

    /** Label with the number */
    UPROPERTY(Category = Labels, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    class UTextRenderComponent* Label1;

    /** Label with the number */
    UPROPERTY(Category = Labels, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    class UTextRenderComponent* Label2;

public:
    // Sets default values for this actor's properties
    AJengaPiece();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Called every frame
    virtual void Tick(float DeltaSeconds) override;

#if WITH_EDITOR
    virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

public:

    UPROPERTY(Category = Materials, EditAnywhere)
    class UMaterial* Material1;

    UPROPERTY(Category = Materials, EditAnywhere)
    class UMaterial* Material2;

private:
    // The number of the piece
    UPROPERTY(Category = Piece, EditAnywhere, meta = (ClampMin = "0", ClampMax = "54"))
    int32 Number;

public:
    //Update the labels
    UFUNCTION(Category = JengaPiece, BlueprintCallable)
    void UpdateLabels();

    UFUNCTION(Category = JengaPiece, BlueprintCallable)
    int32 GetNumber() const;

    UFUNCTION(Category = JengaPiece, BlueprintCallable)
    void SetNumber(int32 number0);

public:

    UFUNCTION()
    void OnClick();

    UFUNCTION()
    void OnRelease();

    UFUNCTION()
    void OnTouchBegin(ETouchIndex::Type FingerIndex);

    UFUNCTION()
    void OnTouchEnd(ETouchIndex::Type FingerIndex);

    UFUNCTION()
    void OnBeginMouseOver();

    UFUNCTION()
    void OnEndMouseOver();

    UFUNCTION()
    void OnBeginTouchOver(ETouchIndex::Type FingerIndex);

    UFUNCTION()
    void OnEndToucheOver(ETouchIndex::Type FingerIndex);
};
