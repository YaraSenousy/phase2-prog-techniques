#include "AddEnd.h"

#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

#include <sstream>

using namespace std;

AddEnd::AddEnd(ApplicationManager* pAppManager) :Action(pAppManager)
{
	endcount++;
}

void AddEnd::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	if (endcount == 1) {
		//Read the (Position) parameter
		pOut->PrintMessage("End Statement: Click to add the statement");

		//get valid point from user
		Position = PointInDrawing(pIn, pOut);
		pOut->ClearStatusBar();
	}
	else {
		pOut->PrintMessage("Invalid! Only one End per flowchart");
	}
	
 }

void AddEnd::Execute()
{
	ReadActionParameters();

	if (endcount == 1) {
		//Calculating left corner of assignement statement block
		Point Corner;
		Corner.x = Position.x - UI.START_WDTH / 2;
		Corner.y = Position.y;

		End* pAssign = new End(Corner);

		pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list
	}
}
