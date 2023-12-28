#include "switchtosim_des.h"

switchtosim_des::switchtosim_des(ApplicationManager* pAppManager) : Action(pAppManager)
{}

void switchtosim_des::ReadActionParameters()
{}

void switchtosim_des::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	if (UI.AppMode == DESIGN)
	{
		pOut->CreateSimulationToolBar();
		
	}
	else if (UI.AppMode == SIMULATION)
	{
		pOut->CreateDesignToolBar();
	}
}

