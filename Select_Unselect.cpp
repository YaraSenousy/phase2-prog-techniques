#include "Select_Unselect.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Connector.h"

Select_Unselect::Select_Unselect(ApplicationManager* pAppManager) : Action(pAppManager)
{
}

void Select_Unselect::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read position parameter
	pOut->PrintMessage("Select/Unselect action: Click on Statement or Connector to Select/ Unselect: ");

	//Get valid point from user
	pIn->GetPointClicked(p);
	pOut->ClearStatusBar();

	//return statement clicked on
	statement = pManager->GetStatement(p);
	connector = pManager->GetConnector(p);
	
}

void Select_Unselect::Execute()
{	
	ReadActionParameters();

	if (pManager->GetSelectedStatement()) {
		(pManager->GetSelectedStatement())->SetSelected(false);
		pManager->SetSelectedStatement(NULL);
	}
	if (pManager->GetSelectedConnector()) {
		(pManager->GetSelectedConnector()->SetSelected(false));
		pManager->SetSelectedConnector(NULL);
	}
		if (statement) {
			statement->SetSelected(!(statement->IsSelected()));
			pManager->SetSelectedStatement(statement);
		}
		if (connector) {
			connector->SetSelected(!(connector->IsSelected()));
			pManager->SetSelectedConnector(connector);
		}	
}
