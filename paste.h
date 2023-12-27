#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "Start.h"
class paste :
    public Action
{

    Statement* copied;
    Point position;

public:
    paste(ApplicationManager* pAppManager);

    void ReadActionParameters();

    void Execute();

};

