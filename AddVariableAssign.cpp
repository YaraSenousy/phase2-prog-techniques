#include "AddVariableAssign.h"



#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddVariableAssign::AddVariableAssign(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddVariableAssign::ReadActionParameters() {

	Input *pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read position parameter
	pOut->PrintMessage("Variable Assignmenet Statemet: Click to add the statement: ");
	pIn->GetPointClicked(p);
	pOut->ClearStatusBar();

	//Asks user in status bar to enter LHS and set the data member
	pOut->PrintMessage("Enter a variable name: ");
	LHS = pIn->GetVariable(pOut);
	pOut->ClearStatusBar();

	//Asks user in status bar to enter RHS and set the data member
	pOut->PrintMessage("Enter a variable name: ");
	RHS = pIn->GetVariable(pOut);
	pOut->ClearStatusBar();

}

void AddVariableAssign::Execute() {

	ReadActionParameters();

	//Calculating left corner of assignment statement block
	Point corner;
	corner.x = p.x - UI.ASSGN_WDTH / 2;
	corner.y = p.y;

	VariableAssign* pAssign = new VariableAssign(corner, LHS, RHS); //set LHS and RHS of pAssign statement with data member set and validates in ReadActionParameter
	pManager->AddStatement(pAssign); 
}
	