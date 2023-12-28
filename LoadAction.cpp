#include "LoadAction.h"

#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

#include <sstream>
using namespace std;

LoadAction::LoadAction(ApplicationManager* pAppManager) :Action(pAppManager)
{
}

void LoadAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("enter filename");
	filename = pIn->GetString(pOut);
	//adding .txt to the filename
	ostringstream T;
	T << filename << ".txt";
	filename = T.str();

	pOut->ClearStatusBar();
}

void LoadAction::Execute()
{
	ReadActionParameters();
	//open the file
	ifstream Infile(filename);
	//check that the file exists
	if (Infile.is_open())
	{
		//call application manager to excute LoadAll
		pManager->LoadAll(Infile);
		Infile.close();
	}
}