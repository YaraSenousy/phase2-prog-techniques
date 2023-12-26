#include "AddCond.h"
#include "Actions/Action.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "GUI/UI_Info.h"
#include "Condition.h"
AddCond::AddCond(ApplicationManager* pAppManager) : Action(pAppManager)
{
}

void AddCond::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read position parameter
	pOut->PrintMessage("Condition statement: click to add the statement");

	//get valid point from user
	position = PointInDrawing(pIn, pOut);
	pOut->ClearStatusBar();

	//Ask user to enter LHS variable to compare, validate and set
	pOut->PrintMessage("Enter a variable name: ");
	LHS=pIn->GetVariable(pOut);
	pOut->ClearStatusBar();
	 //Ask user to enter comp operator, validate and set
	pOut->PrintMessage("Enter comparison operator: ");
	CompOp = pIn->GetCompOperator(pOut);
	pOut->ClearStatusBar();
	//Ask user to enter RHS variable/value, validate and set
	pOut->PrintMessage("Enter variable name/value: ");
	IsValue = pIn->AssignVarOrVal(pOut, RHS);

}

void AddCond::Execute()
{
	ReadActionParameters();

	Point Corner;
	Corner.x = position.x + UI.ASSGN_WDTH/2;
	Corner.y = position.y;

	Condition* pCondition= new Condition(Corner, LHS,CompOp, RHS, IsValue);
	pManager->AddStatement(pCondition);
}

