#include "AddRead.h"
#include "ApplicationManager.h"
#include "Actions/Action.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Read.h"
#include <sstream>
using namespace std;

AddRead::AddRead(ApplicationManager* pAppManager) : Action(pAppManager)
{
}

void AddRead::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	
	//Read the (Position) parameter
	pOut->PrintMessage("Read Statement: Click to add the statement ");

	//get valid point from user
	Position = PointInDrawing(pIn, pOut);
	pOut->ClearStatusBar();
	//Ask user to enter variable name
	pOut->PrintMessage("Enter a variable name to be read: ");
	VarName = pIn->GetVariable(pOut); //The function GetVariable validates
	//Clears status bar
	pOut->ClearStatusBar();

}

void AddRead::Execute()
{
	ReadActionParameters();

	Point Corner;
	//Calculates top left corner to start drawing
	Corner.x = Position.x-UI.IO_WDTH/2;
	Corner.y =Position.y;
	Read* pRead = new Read(Corner, VarName); //Setting the variable name for pRead
	pManager->AddStatement(pRead); //Adds created statement to manager's list


}


