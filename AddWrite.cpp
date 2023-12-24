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
	pOut->PrintMessage("Enter a variable name to be written: ");
	VarName = pIn->GetVariable(pOut); //The function GetVariable validates
	//Clears status bar
	pOut->ClearStatusBar();

}

void AddWrite::Execute()
{
	ReadActionParameters();

	Point Corner;
	//Calculates top left corner to start drawing
	Corner.x = Position.x - UI.IO_WDTH / 2;
	Corner.y = Position.y;
	Write* pWrite = new Write(Corner, VarName); //Setting the variable name for pWrite
	pManager->AddStatement(pWrite); //Adds created statement to manager's list


}