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
	conn = NULL;
}

void DelAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	//Delete clicked, ask user to click on a statement
	pOut->PrintMessage("Delete action: click on a statement to delete it");

	pIn->GetPointClicked(position);
	pOut->ClearStatusBar();
	if (pManager->GetStatement(position) != NULL)
		stat = pManager->GetStatement(position);
	else
		conn = pManager->GetConnector(position);
}

void DelAction::Execute()
{
	ReadActionParameters();
	if (stat != NULL) {
		Point p(0, 0);
		if (stat->check ==2) {
			Condition* cond = dynamic_cast<Condition*>(stat);
			Point P1;
			P1 = cond->getInlet();
			pManager->DeleteConnStat(cond->getOutlet_yesOrno(1), cond->getOutlet_yesOrno(2), cond->getInlet());
		}
		else
			pManager->DeleteConnStat(stat->getOutlet(), p, stat->getInlet());
		
		pManager->DeleteAction(stat);
	}
	if (conn != NULL) {
		pManager->DeleteConn(conn);
	}
}


