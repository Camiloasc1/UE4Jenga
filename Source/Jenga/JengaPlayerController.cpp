// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Jenga.h"
#include "JengaPlayerController.h"

AJengaPlayerController::AJengaPlayerController()
{
    bShowMouseCursor = true;
    bEnableClickEvents = true;
    bEnableMouseOverEvents = true;
    bEnableTouchEvents = true;
    bEnableTouchOverEvents = true;
    DefaultMouseCursor = EMouseCursor::Crosshairs;
}
