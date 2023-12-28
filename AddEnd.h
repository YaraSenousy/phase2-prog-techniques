#ifndef ADD_END_H
#define ADD_END_H

#include "Actions/Action.h"
#include "End.h"
static int endcount = 0;

class AddEnd: public Action
{
private:
	Point Position;

public:
	AddEnd(ApplicationManager* pAppManager);

	//Read End position
	virtual void ReadActionParameters();

	//Create and add an End statement to the list of statements
	virtual void Execute();

};

#endif