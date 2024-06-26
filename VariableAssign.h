#ifndef VARIABLE_ASSIGN_H
#define VARIABLE_ASSIGN_H

#include "Statements/Statement.h"

//Variable Assignment statement class
//The variable assignment statement assigns a variable to a variable
class VariableAssign : public Statement
{
	string LHS; //left handside of assignment (variable)
	string RHS; //right handside of assignment (variable)

	Connector* pOutConn;
	Point LeftCorner;

	virtual void UpdateStatementText();

public:
	VariableAssign(Point Lcorner = Point(-1,-1), string LeftHS = "", string RightHS = "");

	void setLHS(const string& L);
	void setRHS(const string& R);

	virtual void Draw(Output* pOut) const;
	virtual bool InStatement(Point p);
	virtual void Save(ofstream& OutFile);
	void Load(ifstream& Infile);

	Point getInlet();
	Point getOutlet();
};

#endif
