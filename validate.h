#pragma once
#include "Actions\Action.h"
class validate :public Action
{
private:
public:
	validate(ApplicationManager* pAppManager);
	virtual void ReadActionParameters();
	virtual void Execute();
};

