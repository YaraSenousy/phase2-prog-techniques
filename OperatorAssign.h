#ifndef OPPERATOR_ASSIGN_H
#define OPPERATOR_ASSIGN_H

#include "Statements/Statement.h"

//Opperator Assignment statement class
//Opperator assignment statement assigns a value to a variable using arithmetic operations
class OperatorAssign : public Statement{
	string LHS; //Left Handside of assignment (variable)
	string RHS1; //First variable/ value of right handside of assignment 
	bool isValue1; //true if RHS1 is value else if variable
	string RHS2; //Second variable/ value of right handside of assignment
	bool isValue2;  //true if RHS2 is value else if variable
	string opp; //Opperator used in right handside of assignment

	Connector* pOutConn;
	Point Inlet; //used as end point of input connector
	Point Outlet; //used as start point of output connector
	Point LeftCorner; //left corner of statement block
	
	void UpdateStatementText();

public:
	OperatorAssign(Point Lcorner, string LeftHs = "",string RightHs1 = "",bool value1,string RightHsOpp = "",string RightHs2 = "",bool value2);

	void setLHS(const string& L);
	void setRHS1(const string& R1);
	void setRHSO(const string& RO);
	void setRHS2(const string& R2);
	
	void Draw(Output* pOut) const;
};	



#endif