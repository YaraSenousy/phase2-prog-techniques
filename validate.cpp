#include "validate.h"

#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

#include <sstream>
using namespace std;

validate::validate(ApplicationManager* pAppManager) :Action(pAppManager)
{
}

void validate::ReadActionParameters()
{

}

void validate::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	int error_case = pManager->validateAct();
	switch(error_case)
	{
	case 1:
		pOut->PrintMessage("a statement doent have an output connector");
		break;
	case 2:
		pOut->PrintMessage("no start");
		break;
	case 3:
		pOut->PrintMessage("more than one start");
		break;
	case 4:
		pOut->PrintMessage("no end");
		break;
	case 5:
		pOut->PrintMessage("more than 1 end");
		break;
	default:
		pOut->ClearStatusBar();
		break;
	}
}
