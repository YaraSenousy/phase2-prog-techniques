#include "AddWrite.h"
#include "ApplicationManager.h"
#include "Actions/Action.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Read.h"
#include <sstream>
using namespace std;

AddWrite::AddWrite(ApplicationManager* pAppManager) : Action(pAppManager)
{
}

void AddWrite::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Write the (Position) parameter
	pOut->PrintMessage("Write Statement: Click to add the statement ");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
	//Ask user to enter variable name
	pOut->PrintMessage("Enter a variable name or string between quotations to be displayed: ");
	//VarOrString = pIn->GetVariable(pOut); //The function GetVariable validates

	bool invalid = true;
	do {
		VarOrString = pIn->GetString(pOut);
		if (IsVariable(VarOrString)) {
			invalid = false;
		}
		else if (VarOrString[0] == 34 && VarOrString[VarOrString.length() - 1] == 34)
			invalid = false;
		else
			pOut->PrintMessage("Invalid enter a variable name or string between quotations to be displayed: ");
	} while (invalid);
	//Clears status bar
	pOut->ClearStatusBar();

}

void AddWrite::Execute()
{
	ReadActionParameters();

	Point Corner;
	Corner.x = Position.x - UI.IO_WDTH / 2;
	Corner.y = Position.y;
	Write* pWrite = new Write(Corner, VarOrString); //Setting the variable name for pWrite
	pManager->AddStatement(pWrite); //Adds created statement to manager's list
}