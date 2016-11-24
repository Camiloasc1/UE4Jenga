// Fill out your copyright notice in the Description page of Project Settings.

#include "Jenga.h"
#include "JengaPiece.h"
#include "Components/TextRenderComponent.h"

// Sets default values
AJengaPiece::AJengaPiece()
{
    BlockMesh = CreateDefaultSubobject < UStaticMeshComponent > (TEXT("Mesh0"));
    Label1 = CreateDefaultSubobject < UTextRenderComponent > (TEXT("Label1"));
    Label2 = CreateDefaultSubobject < UTextRenderComponent > (TEXT("Label2"));

    RootComponent = BlockMesh;

    Label1->AttachTo(BlockMesh);
    Label2->AttachTo(BlockMesh);

    OnClicked.AddDynamic(this, &AJengaPiece::OnClick);
    OnReleased.AddDynamic(this, &AJengaPiece::OnRelease);

    OnInputTouchBegin.AddDynamic(this, &AJengaPiece::OnTouchBegin);
    OnInputTouchEnd.AddDynamic(this, &AJengaPiece::OnTouchEnd);

    OnBeginCursorOver.AddDynamic(this, &AJengaPiece::OnBeginMouseOver);
    OnEndCursorOver.AddDynamic(this, &AJengaPiece::OnEndMouseOver);

    OnInputTouchEnter.AddDynamic(this, &AJengaPiece::OnBeginTouchOver);
    OnInputTouchLeave.AddDynamic(this, &AJengaPiece::OnEndToucheOver);

    Material1 = nullptr;
    Material2 = nullptr;

    Number = 0;

    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AJengaPiece::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AJengaPiece::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

#if WITH_EDITOR
void AJengaPiece::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
    //Get all of our components
    TArray<UActorComponent*> OwnedComponents;
    GetComponents(OwnedComponents);

    //Get the name of the property that was changed
    FName PropertyName =
    (PropertyChangedEvent.Property != nullptr) ?
    PropertyChangedEvent.Property->GetFName() : NAME_None;

    // We test using GET_MEMBER_NAME_CHECKED so that if someone changes the property name
    // in the future this will fail to compile and we can update it.
    if ((PropertyName == GET_MEMBER_NAME_CHECKED(AJengaPiece, Number)))
    {
        UpdateLabels();
    }

    // Call the base class version
    Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

void AJengaPiece::UpdateLabels()
{
    FText numberText = FText::AsNumber(Number);
    Label1->SetText(numberText);
    Label2->SetText(numberText);
}

int32 AJengaPiece::GetNumber() const
{
    return Number;
}

void AJengaPiece::SetNumber(int32 number0)
{
    Number = number0;
    UpdateLabels();
}

void AJengaPiece::OnClick()
{
    OnBeginMouseOver();
}

void AJengaPiece::OnRelease()
{
    Destroy();
}

void AJengaPiece::OnTouchBegin(ETouchIndex::Type FingerIndex)
{
    OnClick();
}

void AJengaPiece::OnTouchEnd(ETouchIndex::Type FingerIndex)
{
    OnRelease();
}

void AJengaPiece::OnBeginMouseOver()
{
    BlockMesh->SetMaterial(0, Material2);
}

void AJengaPiece::OnEndMouseOver()
{
    BlockMesh->SetMaterial(0, Material1);
}

void AJengaPiece::OnBeginTouchOver(ETouchIndex::Type FingerIndex)
{
    OnBeginMouseOver();
}

void AJengaPiece::OnEndToucheOver(ETouchIndex::Type FingerIndex)
{
    OnEndMouseOver();
}
