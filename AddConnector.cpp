#include "AddConnector.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddConnector::AddConnector(ApplicationManager* pAppManager) : Action(pAppManager)
{
	start_stat = NULL;
	end_stat = NULL;
}

void AddConnector::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//read start_stat from user
	pOut->PrintMessage("Select the first statement");
	Point p;
	do {
		pIn->GetPointClicked(p);
		start_stat = pManager->GetStatement(p);
		//todo: check that start_stat pOutConn is null
	} while (start_stat == NULL);
	//read end_stat from user
	pOut->PrintMessage("Select the second statement");
	do {
		pIn->GetPointClicked(p);
		end_stat = pManager->GetStatement(p);
	} while (end_stat = NULL);
	
	pOut->ClearStatusBar();
}

void AddConnector::Execute()
{
	ReadActionParameters();
	//creating new connector
	Connector* pConn = new Connector(start_stat, end_stat);
	//Create and add a connector to application managers's connector list
	pManager->AddConnector(pConn);
}
