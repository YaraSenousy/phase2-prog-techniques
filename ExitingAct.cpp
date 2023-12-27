#include "ExitingAct.h"
#include "Actions/Action.h"
#include "ApplicationManager.h"

ExitingAct::ExitingAct(ApplicationManager* pAppManager) :Action(pAppManager)
{
	pManager = pAppManager;
}

void ExitingAct::ReadActionParameters()
{
	//No parameters to be read
}

void ExitingAct::Execute()
{
	pManager->ExitAct();
}

