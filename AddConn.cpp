#include "AddConn.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Condition.h"
#include <sstream>
#include "End.h"
#include "Start.h"
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddConn::AddConn(ApplicationManager* pAppManager) : Action(pAppManager)
{
	start_stat = NULL;
	end_stat = NULL;

	Outlet_branch = 0; //by defualt the branch isnt yes or no branch
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
	if (dynamic_cast<End*>(start_stat)) {
		start_stat = nullptr;
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
	if (dynamic_cast<Condition*>(start_stat)) {
		Condition* cond = dynamic_cast<Condition*>(start_stat);
		if (cond->getpConnOut(Outlet_branch) != NULL)
			start_stat = NULL;
			
	}
	//make sure each statement has one/two output connector
	if (start_stat) {
		if (start_stat->GetConnOut() != NULL)
			start_stat = NULL;
	}

	//read end_stat from user
	pOut->PrintMessage("Select the second statement");
	pIn->GetPointClicked(p);
	end_stat = pManager->GetStatement(p);
	//check it isnt start statement
	if (dynamic_cast<Start*>(end_stat)) {
		end_stat = nullptr;
	}
	pOut->ClearStatusBar();
}

void AddConn::Execute()
{
	ReadActionParameters();
	//creating new connector
	if (start_stat && end_stat) {
		Connector* pConn = new Connector(start_stat, end_stat,Outlet_branch);
		//setting the start and end point
		pConn->setStartPoint();
		pConn->setEndPoint();
		//setting the pointer in start statement
		if (dynamic_cast<Condition*>(start_stat)) {
			Condition* cond = dynamic_cast<Condition*>(start_stat);
			cond->SetpConnOut(pConn, Outlet_branch);
		}
		else
			start_stat->SetpConnOut(pConn);
		//Create and add a connector to application managers's connector list
		pManager->AddConnector(pConn);
	}
}
