#include "Copy.h"

Copy::Copy(ApplicationManager* pAppManager) : Action(pAppManager)
{
}

void Copy::ReadActionParameters()
{

}

void Copy::Execute()
{
	
	pManager->SetClipboard(copied);

}
