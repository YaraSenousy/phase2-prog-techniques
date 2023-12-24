#ifndef DELETE_ACTION_H
#define DELETE_ACTION_H
#include "Actions/Action.h"
#include "Statements/Statement.h"
class DeleteAction : public Action
{
private:
	Point position;
	Statement * stat;

public:
	DeleteAction(ApplicationManager* pAppManager);
	void ReadActionParameters();
	void Execute();

};
#endif


