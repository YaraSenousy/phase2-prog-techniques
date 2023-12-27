#include "paste.h"

paste::paste(ApplicationManager* pAppManager): Action(pAppManager)
{}

void paste::ReadActionParameters()
{
	if (pManager->GetClipboard() != NULL)
	{
		Input* pIn = pManager->GetInput();
		Output* pOut = pManager->GetOutput();

		pOut->PrintMessage("Click where you want to copy. Click anywhere to continue. ");
		pIn->GetPointClicked(position);
		pOut->ClearStatusBar();


	}
	else
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("No items to paste. Click anywhere to continue.");
		pOut->ClearStatusBar();
	}
}

void paste::Execute()
{
	ReadActionParameters();
	Statement* ToCopy = pManager->GetClipboard();

	if (dynamic_cast<Start*>(ToCopy) != NULL)
	{
		Start* pAssign = new Start(position);

		pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list
	}
}
