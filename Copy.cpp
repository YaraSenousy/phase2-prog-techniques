#include "Copy.h"

Copy::Copy(ApplicationManager* pAppManager) : Action(pAppManager)
{
}

void Copy::ReadActionParameters()
{

}

void Copy::Execute()
{
	copied = pManager->GetSelectedStatement();
	if ( copied != NULL)
	{
		pManager->SetClipboard(copied);
	}
	
	copied->SetSelected(false) ;
	pManager->SetSelectedStatement(NULL);


}
