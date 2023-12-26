#include "ApplicationManager.h"
#include "Actions\AddValueAssign.h"
#include "AddStart.h"
#include "AddRead.h"
#include "AddVariableAssign.h"
#include "AddWrite.h"
#include "AddEnd.h"
#include "AddConn.h"
#include "AddOperatorAssign.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "DelAction.h"
#include "AddCond.h"
#include "SaveAction.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	StatCount = 0;
	ConnCount = 0;
	pSelectedStat = NULL;	//no Statement is selected yet
	pClipboard = NULL;
	
	//Create an array of Statement pointers and set them to NULL		
	for(int i=0; i<MaxCount; i++)
	{
		StatList[i] = NULL;	
		ConnList[i] = NULL;
	}
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//


ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to ActioType, create the corresponding action object
	switch (ActType)
	{
		case DEL:
			pAct = new DelAction(this);
			break;
		case SAVE:
			pAct = new SaveAction(this);
			break;
		case ADD_VALUE_ASSIGN:
			pAct = new AddValueAssign(this);
			break;

		case ADD_CONDITION:
			///create AddCondition Action here
			pAct = new AddCond(this);
			break;

		case SELECT:
			///create Select Action here

			break;

		case EXIT:
			///create Exit Action here
			
			break;
		
		case STATUS:
			return;

		case ADD_VAR_ASSIGN:
			pAct = new AddVariableAssign(this);
			break;

		case ADD_READ:
			pAct = new AddRead(this);
			break;
		case ADD_WRITE:
			pAct = new AddWrite(this);
			break;
		case ADD_START:
			pAct = new AddStart(this);
			break;
		case ADD_END:
			pAct = new AddEnd(this);
			break;
		case ADD_OPER_ASSIGN:
			pAct = new AddOperatorAssign(this);
			break;
		case ADD_CONNECTOR:
			pAct = new AddConn(this);
			break;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
	}
}

void ApplicationManager::DeleteAction(Statement*statd)
{
	for (int i = 0; i < StatCount; i++) {
		if (StatList[i] == statd) {
			delete StatList[i];
			StatList[i] = StatList[StatCount - 1];
			StatList[StatCount - 1] = NULL;
			StatCount--;
		}
	}
}

void ApplicationManager::DeleteConn(Point Pout1,Point Pout2,Point Pin)
{
	for (int i = 0; i < ConnCount; i++) {
		Point StartPoint = ConnList[i]->getStartPoint();
		if ((Pout1.x == StartPoint.x && Pout1.y == StartPoint.y)
			|| (Pout2.x == StartPoint.x && Pout2.y == StartPoint.y)
			|| (Pin.x == StartPoint.x && Pin.y == StartPoint.y)) {
			delete ConnList[i];
			ConnList[i] = ConnList[ConnCount - 1];
			ConnList[ConnCount - 1] = NULL;
			ConnCount--;
		}
	}
}


void ApplicationManager::SaveAll(ofstream& OutFile)
{
	//adding the number of statements to the file
	OutFile << StatCount << endl;
	//calling the Save function for each statement
	for (int i{}; i < StatCount; i++) {
		StatList[i]->Save(OutFile);
	}
	//adding the number of connectors to the file
	OutFile << ConnCount << endl;
	//calling the Save funciton for each connector
	for (int i{}; i < ConnCount; i++) {
		ConnList[i]->Save(OutFile);
	}
}

//==================================================================================//
//						Statements Management Functions								//
//==================================================================================//


//Add a statement to the list of statements
void ApplicationManager::AddStatement(Statement *pStat)
{
	if(StatCount < MaxCount)
		StatList[StatCount++] = pStat;
	
}

////////////////////////////////////////////////////////////////////////////////////
Statement *ApplicationManager::GetStatement(Point P) const
{
	//If this point P(x,y) belongs to a statement return a pointer to it.
	//otherwise, return NULL


	///Add your code here to search for a statement given a point P(x,y)	
	///WITHOUT breaking class responsibilities
	for (int i{}; i < StatCount; i++) {
	//check if the point is within the statement 
		if (StatList[i]->InStatement(P)) {
			return StatList[i];
		}
	}
	return NULL;
}

//==================================================================================//
//						Connectors Management Functions								//
//==================================================================================//

//add a connector to the list of connectors
void ApplicationManager::AddConnector(Connector* pConn)
{
	if (ConnCount < MaxCount)
		ConnList[ConnCount++] = pConn;
}
//check if the Point belongs to a connector
Connector* ApplicationManager::GetConnector(Point P) const
{
	//loop on all connectors
	for (int i{}; i++; i < ConnCount) {
		//check if the point belong to a connector and return a pointer to it
		if (ConnList[i]->IsConnector(P)) {
			ConnList[i];
		}
	}
	return nullptr;
}
////////////////////////////////////////////////////////////////////////////////////
//Returns the selected statement
Statement *ApplicationManager::GetSelectedStatement() const
{	return pSelectedStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedStatement(Statement *pStat)
{	pSelectedStat = pStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Returns the Clipboard
Statement *ApplicationManager::GetClipboard() const
{	return pClipboard;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the Clipboard
void ApplicationManager::SetClipboard(Statement *pStat)
{	pClipboard = pStat;	}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//


//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();

	//Draw all statements
	for(int i=0; i<StatCount; i++)
		StatList[i]->Draw(pOut);
	
	//Draw all connections
	for(int i=0; i<ConnCount; i++)
		ConnList[i]->Draw(pOut);

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////


//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<StatCount; i++)
		delete StatList[i];
	for(int i=0; i<StatCount; i++)
		delete ConnList[i];
	delete pIn;
	delete pOut;
	
}
