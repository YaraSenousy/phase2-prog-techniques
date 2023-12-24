#include "AddConn.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddConn::AddConn(ApplicationManager* pAppManager) : Action(pAppManager)
{
	start_stat = NULL;
	end_stat = NULL;
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
		//todo: check that start_stat pOutConn is null
	//read end_stat from user
	pOut->PrintMessage("Select the second statement");
	pIn->GetPointClicked(p);
	end_stat = pManager->GetStatement(p);
	
	pOut->ClearStatusBar();
}

void AddConn::Execute()
{
	ReadActionParameters();
	//creating new connector
	if (start_stat && end_stat) {
		Connector* pConn = new Connector(start_stat, end_stat);
		//Create and add a connector to application managers's connector list
		pManager->AddConnector(pConn);
	}
}
