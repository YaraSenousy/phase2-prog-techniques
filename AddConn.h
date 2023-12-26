#pragma once
#include "Actions/Action.h"
#include "Connector.h"
class AddConn : public Action
{
private:
	Statement* start_stat;
	Statement* end_stat;

	int Outlet_branch; //to set the type of the branch (yes,no,defualt)

public:
	AddConn(ApplicationManager* pAppManager);

	//Read start and end statements connected by the connector 
	virtual void ReadActionParameters();

	//Create and add a connector to application managers's connector list
	virtual void Execute();

};

