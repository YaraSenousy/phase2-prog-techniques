#ifndef ADD_START_H
#define ADD_START_H

#include "Actions/Action.h"
#include "Statements/Start.h"

class AddStart:public Action
{
private:
	Point position;

public:
	AddStart(ApplicationManager* pAppManager);
	virtual void Execute();
};

#endif

