#include "DelAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

#include <sstream>
using namespace std;

DelAction::DelAction(ApplicationManager* pAppManager) :Action(pAppManager)
{
	stat = NULL;
}

void DelAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	//Delete clicked, ask user to click on a statement
	pOut->PrintMessage("Delete action: click on a statement to delete it");

	pIn->GetPointClicked(position);
	pOut->ClearStatusBar();

	stat = pManager->GetStatement(position);
}

void DelAction::Execute()
{
	ReadActionParameters();
	if (stat != NULL) {
		pManager->DeleteAction(stat);
	}
}


