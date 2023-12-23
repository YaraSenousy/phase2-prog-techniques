#ifndef ADD_VARIABLE_ASSIGN_H
#define ADD_VARIABLE_ASSIGN_H

#include "Actions/Action.h"
#include "VariableAssign.h"

//Add Variable Assignment Statement Action
//This class is responsible for
//1. Getting Assignment statement coordinates from the user (from parameters)
//2. Getting LHS and RHS of statement from the user (from parameters)
//3. Creating object of Assignment class and passing parameters
//4. Adding created object list of statements to application manager
class AddVariableAssign : public Action
{
	//private data members of actions 
	Point p; // position where user clicks to add statement
	string LHS; // LHS (string since this is variable assignment)
	string RHS; // RHS (also string since this is variable assignment)

public:
	AddVariableAssign(ApplicationManager* pAppManager);

	//Read Assignment statements position
	virtual void ReadActionParameters();

	//Create and add assignment statement to the list of statements
	virtual void Execute();
};

#endif