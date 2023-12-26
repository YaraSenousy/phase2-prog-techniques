#include "AddConn.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Condition.h"
#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddConn::AddConn(ApplicationManager* pAppManager) : Action(pAppManager)
{
	start_stat = NULL;
	end_stat = NULL;

	//Outlet_branch = 0; //by defualt the branch isnt yes or no branch
}

void AddConn::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//read start_stat from user
	pOut->PrintMessage("Select the first statement");
	Point p;
	pIn->GetPointClicked(p);
	start_stat = pManager->GetStatement(p);
	//check it isnt end statement
	if ((start_stat->getInlet()).x == -1) {
		start_stat = NULL;
	}
	if (dynamic_cast<Condition*>(start_stat)) {
		pOut->PrintMessage("type 1 for Yes otherwise No");
		string branchtype = pIn->GetString(pOut);
		if (branchtype == "1") {
			Outlet_branch = 1; //yes branch
		}
		else
			Outlet_branch = 2; //no branch
	}


	//read end_stat from user
	pOut->PrintMessage("Select the second statement");
	pIn->GetPointClicked(p);
	end_stat = pManager->GetStatement(p);
	//check it isnt start statement
	if ((end_stat->getOutlet()).x == -1) {
		end_stat = NULL;
	}
	pOut->ClearStatusBar();
}

void AddConn::Execute()
{
	ReadActionParameters();
	//creating new connector
	if (start_stat != NULL && end_stat != NULL) {
		Connector* pConn = new Connector(start_stat, end_stat);
		//setting the start and end point
		pConn->setStartPoint(start_stat->getOutlet());
		

		pConn->setEndPoint(end_stat->getInlet());
		//Create and add a connector to application managers's connector list
		pManager->AddConnector(pConn);
	}
}
