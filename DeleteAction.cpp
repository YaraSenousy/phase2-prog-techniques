#include "DeleteAction.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

DeleteAction::DeleteAction(ApplicationManager* pAppManager) : Action(pAppManager)
{
}

void DeleteAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	//Delete clicked, ask user to click on a statement
	pOut->PrintMessage("Delete action: click on a statement to delete it");

	pIn->GetPointClicked(position);
	pOut->ClearStatusBar();

	stat = pManager->GetStatement(position);
}

void DeleteAction::Execute()
{
	if (stat != NULL) {
		pManager->DeleteAction(stat);
	}
}


