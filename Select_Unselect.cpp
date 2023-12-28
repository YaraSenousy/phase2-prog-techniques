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

	//checks if there is a selected statement
	if (pManager->GetSelectedStatement()) {
		// deselects if reclicked
		if (pManager->GetSelectedStatement() == statement) {
			pManager->SetSelectedStatement(NULL);
		}
		//deselcts previously selected statement
		else {
			pManager->GetSelectedStatement()->SetSelected(false);
			pManager->SetSelectedStatement(NULL);
		}
	}

	//checks if there is a selected connector
	if (pManager->GetSelectedConnector()) {
		// deselcts if reclicked
		if (pManager->GetSelectedConnector() == connector) {
			pManager->SetSelectedConnector(NULL);
		}
		//deselects previously selected connector
		else {
			pManager->GetSelectedConnector()->SetSelected(false);
			pManager->SetSelectedConnector(NULL);
		}
	}
	//select or unselect clicked statement
		if (statement) {
			if (statement->IsSelected()==true) {
				statement->SetSelected(false);
				pManager->SetSelectedStatement(NULL);
			}
			else {
				statement->SetSelected(true);
				pManager->SetSelectedStatement(statement);
			}
		}
	//select or unselect clicked connector
		else if (connector) {
			if (connector->IsSelected()==true) {
				connector->SetSelected(false);
				pManager->SetSelectedConnector(NULL);
			}
			else {
				connector->SetSelected(true);
				pManager->SetSelectedConnector(connector);
			}
		}	
}
