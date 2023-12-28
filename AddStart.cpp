#include "AddStart.h"

#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

#include <sstream>

using namespace std;

AddStart::AddStart(ApplicationManager* pAppManager) :Action(pAppManager)
{
	startcount++;
}


void  AddStart::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	if (startcount == 1) {
		//Read the (Position) parameter
		pOut->PrintMessage("Start Statement: Click to add the statement");

		//get valid point from user
		Position = PointInDrawing(pIn, pOut);
		pOut->ClearStatusBar();
	}
	else {
		pOut->PrintMessage("Invalid! Only one Start per flowchart. ");
	}
	

 }

 void AddStart::Execute()
{
	 ReadActionParameters();
	 
	 if (startcount == 1) {
		 //Calculating left corner of assignement statement block
		 Point Corner;
		 Corner.x = Position.x - UI.START_WDTH / 2;
		 Corner.y = Position.y;

		 Start* pAssign = new Start(Corner);

		 pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list
	 }
}


