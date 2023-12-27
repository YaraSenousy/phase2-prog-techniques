#ifndef DELETE_ACTION_H
#define DELETE_ACTION_H
#include "Actions/Action.h"
#include "Statements/Statement.h"
class DelAction : public Action
{
private:
	Point position;
	Statement * stat;
	Connector* conn;

public:
	DelAction(ApplicationManager *pAppManager);
	virtual void ReadActionParameters();
	virtual void Execute();

};
#endif


