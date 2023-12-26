#include "DelAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Condition.h"

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

		if (dynamic_cast<Condition*>(stat))
			pManager->DeleteConn(stat->getOutlet_yesOrno(1), stat->getOutlet_yesOrno(2), stat->getInlet());
		else
			pManager->DeleteConn(stat->getOutlet(), NULL, stat->getInlet());
		pManager->DeleteAction(stat);
	}
}


