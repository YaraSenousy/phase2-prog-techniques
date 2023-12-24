#include "AddOperatorAssign.h"

#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

#include <sstream>
using namespace std;

//constuctor: set the ApplicationManager pointer inside this action
AddOperatorAssign::AddOperatorAssign(ApplicationManager* pAppManager) : Action(pAppManager) {

}

void AddOperatorAssign::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the "pos" (position) parameter
	pOut->PrintMessage("Operator Assignment Statement: Click to add the statement ");

	pIn->GetPointClicked(pos);
	pOut->ClearStatusBar();

	//Ask user in status bar to enter the LHS and set the data member
	pOut->PrintMessage("Enter a variable name: ");
	LHS = pIn->GetVariable(pOut);

	//Ask user in status bar to enter first variable/value in RHS, validate and set the data member
	pOut->PrintMessage("Enter a variable name/ value: ");;
	string temp;
	bool isValue = pIn->AssignVarOrVal(pOut, temp);
	if (isValue) {
		double RHS1 = stod(temp);
	}
	else {
		string RHS1 = temp;
	}

}
