#ifndef ADD_WRITE_H
#define ADD_WRITE_H
#include "Actions/Action.h"
#include "Write.h"

class AddWrite : public Action
{
private:
	Point Position;
	string VarName;

public:
	AddWrite(ApplicationManager* pAppManager);
	void ReadActionParameters();
	void Execute();
};

#endif


