#include "SaveAction.h"

#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

#include <sstream>
using namespace std;

SaveAction::SaveAction(ApplicationManager* pAppManager):Action(pAppManager)
{
}

void SaveAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("enter a valid filename");
	filename = pIn->GetString(pOut);
	pOut->ClearStatusBar();
}

void SaveAction::Execute()
{
	ReadActionParameters();
	//open the file
	ofstream Outfile(filename);
	//call application manager to excute SaveAll
	pManager->SaveAll(Outfile);
	Outfile.close();
}
