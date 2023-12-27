#ifndef SELECT_UNSELECT_H
#define SELECT_UNSELECT_H
#include "Actions/Action.h"
#include "Statements/Statement.h"

class Select_Unselect :
    public Action
{
    Point p;
    Statement* statement;
    Connector* connector;

public:
    Select_Unselect(ApplicationManager* pAppManager);
    void ReadActionParameters();
    void Execute();
};
#endif

