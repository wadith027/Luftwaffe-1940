#pragma once
#include"Loader.h"

void stageDraw()
{
	if (gameStage == 1)stage.setString("Stage 1");
	if (gameStage == 2)stage.setString("Stage 2");
	if (gameStage == 3)stage.setString("Stage 3");
	if (gameStage == 4)stage.setString("Stage 4");
	if (gameStage == 5)stage.setString("Stage 5");
	stage.setPosition(550.0f, 250.0f);

}