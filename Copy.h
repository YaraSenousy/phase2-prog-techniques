#pragma once
#include "Actions/Action.h"
#include "Statements/Statement.h"

class Copy :
    public Action
{
	Statement* copied;

public:
	Copy(ApplicationManager* pAppManager);
	

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute() ;
};

