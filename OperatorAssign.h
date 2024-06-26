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
	Point LeftCorner;

	Connector* pOutConn;
	
	
	void UpdateStatementText();

public:
	OperatorAssign(Point Lcorner=Point(-1,-1), string LeftHs = "", string RightHs1 = "", bool value1 = false, string RightHsOpp = "", string RightHs2 = "", bool value2 = false);

	void setLHS(const string& L);
	void setRHS1(const string& R1);
	void setRHSO(const string& RO);
	void setRHS2(const string& R2);
	
	void Draw(Output* pOut) const;
	virtual bool InStatement(Point p);
	virtual void Save(ofstream& OutFile);
	void Load(ifstream& Infile);

};	



#endif