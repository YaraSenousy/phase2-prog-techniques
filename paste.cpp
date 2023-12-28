#include "paste.h"

paste::paste(ApplicationManager* pAppManager): Action(pAppManager)
{}

void paste::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Click where you want to paste. Click anywhere to continue. ");
	pIn->GetPointClicked(position);
	pOut->ClearStatusBar();

}

void paste::Execute()
{
	Statement* ToCopy = pManager->GetClipboard();
	if (ToCopy != NULL)
	{
		ReadActionParameters();
		Statement* ptr;

		if (dynamic_cast<Start*>(ToCopy))
		{
			ptr = new Start(position);
		}
		else if (dynamic_cast<End*>(ToCopy) != NULL)
		{
			ptr = new End(position);

			
		}
		else if (dynamic_cast<ValueAssign*>(ToCopy) != NULL)
		{
			
			ptr = new ValueAssign(position);
			*ptr = *ToCopy;

			
		}
		else if (dynamic_cast<VariableAssign*>(ToCopy) != NULL)
		{
			ptr = new VariableAssign(position);
			*ptr = *ToCopy;
			
		}
		else if (dynamic_cast<OperatorAssign*>(ToCopy) != NULL)
		{
			ptr = new OperatorAssign(position);
			*ptr = *ToCopy;
			
		}
		else if (dynamic_cast<Condition*>(ToCopy) != NULL)
		{
			ptr = new Condition(position);
			*ptr = *ToCopy;
		}
		else if (dynamic_cast<Read*>(ToCopy) != NULL)
		{
			ptr = new Read(position);
			*ptr = *ToCopy;
		}
		else if (dynamic_cast<Write*>(ToCopy) != NULL)
		{
			ptr = new Write(position);
			*ptr = *ToCopy;
		}
		pManager->AddStatement(ptr);

		



	}

	else
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("No items to paste. Click anywhere to continue.");
		
	}
	
	

}
