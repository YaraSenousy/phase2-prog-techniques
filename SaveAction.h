#pragma once
#include "Actions\Action.h"
#include <fstream>

class SaveAction: public Action
{
	// save the filename 
	string filename;

public:
	SaveAction(ApplicationManager* pAppManager);
	//read the filename from the user
	virtual void ReadActionParameters();
	//open the file and call SaveAll
	virtual void Execute();
};

