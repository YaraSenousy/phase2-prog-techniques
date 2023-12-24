#ifndef ADD_OPERATOR_ASSIGN_H
#define ADD_OPERATOR_ASSIGN_H

#include "Actions/Action.h"
#include "OperatorAssign.h"

//Add Operator Assignment Statement Action
//This class is responsible for
//1. Getting Assignment statement coordinates from user (from parameter)
//2. Getting LHS, RHS1, RHSO, and RHS2 of the statement from the user (from parameters)
//3. Creating an object of Assignment ckass and passing its parameters
//4. Adding created object to list of statements in application manager

class AddOperatorAssign : public Action
{
	//private data members 
	Point pos; 
	string LHS; // LHS (string since this is a variable)
	string RHS1; // RHS1 (string since we are unsure whether user enters variable or value)
	bool isValue1; //true if RHS1 is value else if variable
	string RHSO; // RHSO (string since this is an operator)
	string RHS2; // RHS2 (string since we are unsure whether user enters variable or value)
	bool isValue2;  //true if RHS2 is value else if variable

public:
	AddOperatorAssign(ApplicationManager* pAppManager);

	//Read Assignment statement position
	void ReadActionParameters();

	//Create and add an assignment statement to the list of statements
	void Execute();

};

#endif
