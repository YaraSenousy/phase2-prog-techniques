#ifndef ADD_READ_H
#define ADD_READ_H

#include "Actions/Action.h"
#include "Read.h"

class AddRead : public Action
{
private:
	Point Position;
	string VarName;

public:
	AddRead(ApplicationManager* pAppManager);
	void ReadActionParameters();
	void Execute();
};
#endif

