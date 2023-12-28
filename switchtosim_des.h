#pragma once
#include "ApplicationManager.h"
#include "Actions/Action.h"
class switchtosim_des: public Action
{
public:
	switchtosim_des(ApplicationManager* pAppManager);

	void ReadActionParameters();

	void Execute();

};

