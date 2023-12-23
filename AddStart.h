#ifndef ADD_START_H
#define ADD_START_H

#include "Actions/Action.h"
#include "Start.h"

class AddStart:public Action
{
private:
	Point Position;

public:
	AddStart(ApplicationManager* pAppManager);

	//Read start position
	virtual void ReadActionParameters();

	//Create and add a start statement to the list of statements
	virtual void Execute();
};

#endif

