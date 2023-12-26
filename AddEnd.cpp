#include "AddEnd.h"

#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

#include <sstream>

using namespace std;

AddEnd::AddEnd(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddEnd::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("End Statement: Click to add the statement");

	//get valid point from user
	Position = PointInDrawing(pIn, pOut);
	pOut->ClearStatusBar();

 }

void AddEnd::Execute()
{
	ReadActionParameters();

	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.START_WDTH / 2;
	Corner.y = Position.y;

	End* pAssign = new End(Corner);

	pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list

}
