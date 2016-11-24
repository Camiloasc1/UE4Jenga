// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Jenga.h"
#include "JengaGameMode.h"
#include "JengaPlayerController.h"

AJengaGameMode::AJengaGameMode()
{
	// no pawn by default
	DefaultPawnClass = NULL;
	// use our own player controller class
	PlayerControllerClass = AJengaPlayerController::StaticClass();
}
