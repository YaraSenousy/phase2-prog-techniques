#include "AddOperatorAssign.h"

#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "OperatorAssign.h"

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
	pOut->PrintMessage("Enter a variable name/ value: ");
	isValue1 = pIn->AssignVarOrVal(pOut,RHS1);

	pOut->PrintMessage("Enter an arithemetic operation: ");
	RHSO = pIn->GetArithOperator(pOut);

	pOut->PrintMessage("Enter a variable name/ value: ");
	isValue2 = pIn->AssignVarOrVal(pOut, RHS2);

}

void AddOperatorAssign::Execute()
{
	ReadActionParameters();

	//Calculating left corner of assignment statement block
	Point corner;
	corner.x = pos.x - UI.ASSGN_WDTH / 2;
	corner.y = pos.y;

	OperatorAssign* pAssign = new OperatorAssign(corner,LHS,RHS1,isValue1,RHSO,RHS2,isValue2); //set LHS and RHS of pAssign statement with data member set and validates in ReadActionParameter
	pManager->AddStatement(pAssign);
}
