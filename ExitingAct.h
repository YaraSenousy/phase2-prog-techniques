#ifndef EXITING_ACT_H
#define EXITING_ACT_H
#include "Actions/Action.h"
class ExitingAct : public Action
{
public:
	ExitingAct(ApplicationManager* pAppManager);
	void ReadActionParameters();
	void Execute();
};

#endif

