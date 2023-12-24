#include "AddStart.h"

#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

#include <sstream>

using namespace std;

AddStart::AddStart(ApplicationManager* pAppManager) :Action(pAppManager)
{}


void  AddStart::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();


	//Read the (Position) parameter
	pOut->PrintMessage("Start Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

 }

 void AddStart::Execute()
{
	 ReadActionParameters();

	 //Calculating left corner of assignement statement block
	 Point Corner;
	 Corner.x = Position.x - UI.START_WDTH / 2;
	 Corner.y = Position.y;

	 Start* pAssign = new Start(Corner);

	 pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list

}


