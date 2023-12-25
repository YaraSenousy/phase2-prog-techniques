#ifndef ADD_COND_H
#define ADD_COND_H

#include "ApplicationManager.h"
#include "Actions/Action.h"
class AddCond : public Action
{
private:
	Point position;
	string LHS;
	string CompOp;
	string RHS;
	bool IsValue;
	
public:
	AddCond(ApplicationManager* pAppManager);
	void ReadActionParameters();
	void Execute();
};
#endif
