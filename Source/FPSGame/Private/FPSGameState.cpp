﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameState.h"

#include "FPSPlayerController.h"
#include "Engine/PawnIterator.h"

void AFPSGameState::MulticastOnMissionComplete_Implementation(APawn* InstigatorPawn, bool bMissionSucess)
{
	// for(FConstPawnIterator It = GetWorld() -> GetPawnIterator() ; It ; It ++)
	// {
	// 	APawn* Pawn = It -> Get();
	// 	if(Pawn && Pawn -> IsLocallyControlled())
	// 	{
	// 		Pawn ->DisableInput(nullptr);
	// 	}
	// }

	for(FConstPlayerControllerIterator It = GetWorld() -> GetPlayerControllerIterator() ; It ; It ++)
	{
		AFPSPlayerController* PC = Cast<AFPSPlayerController>(It -> Get());
		if(PC)
		{
			PC -> OnMissionCompeleted(InstigatorPawn , bMissionSucess);

			APawn* MyPawn = PC -> GetPawn();
			if(MyPawn)
			{
				MyPawn -> DisableInput(nullptr);
			}
		}
	}
}
