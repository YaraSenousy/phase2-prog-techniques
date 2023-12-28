#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "Start.h"
#include "End.h"
#include "Statements/ValueAssign.h"
#include "VariableAssign.h"
#include "OperatorAssign.h"
#include "Condition.h"
#include "Read.h"
#include "Write.h"

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

