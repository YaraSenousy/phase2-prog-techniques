#include "LoadAction.h"

#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Start.h"
#include "End.h"
#include "Write.h"
#include "Read.h"
#include "Condition.h"
#include "statements\ValueAssign.h"
#include "VariableAssign.h"
#include "OperatorAssign.h"

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
		int s_count;
		Infile >> s_count;
		Statement* pStat;
		int statement_type;
		for (int i{}; i < s_count; i++) {
			//reads the statement type and creates an object
			Infile >> statement_type;
			//create new statement
			switch (statement_type)
			{
			case 1:
				pStat = new Start();
				break;
			case 2:
				pStat = new End();
				break;
			case 3:
				pStat = new ValueAssign();
				break;
			case 4:
				pStat = new VariableAssign();
				break;
			case 5:
				pStat = new OperatorAssign();
				break;
			case 6:
				pStat = new Condition();
				break;
			case 7:
				pStat = new Read();
				break;
			case 8:
				pStat = new Write();
				break;
			}
			//call load fucntion for the statement
			pStat->Load(Infile);
			//add statement to the StatList
			pManager->AddStatement(pStat);
		}
		Infile.close();
	}

	/*
	* void ApplicationManager::LoadAll(ifstream& InFile)
{
	//removing any statement or connector on the drawing area first
	//delete[] StatList;
	//delete[] ConnList;
	//reading from the file the number of statements
	
}
	*/
}