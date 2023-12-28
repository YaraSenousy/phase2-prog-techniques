#pragma once
#include "Actions\Action.h"
#include <fstream>

class LoadAction : public Action
{
private:
	// save the filename 
	string filename;
public:
	LoadAction(ApplicationManager* pAppManager);
	//read the filename from the user
	virtual void ReadActionParameters();
	//open the file and call LoadAll
	virtual void Execute();
};

