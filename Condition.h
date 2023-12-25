#ifndef CONDITON_H
#define CONDITON_H
#include "Statements/Statement.h"
class Condition : public Statement
{
private:
	string LHS; //left hand side variable
	string CompOp; //comparison operator
	string RHS; //right hand side variable/value
	bool IsValue; //true if rhs is value, false if variable

	Connector* pOutConnTrue; //first connector in case condition is true
	Connector* pOutConnFalse; //second connector in case condition false
	Point Inlet; //only one inlet
	Point OutletTrue; //outlet in case condition is true
	Point OutletFalse; //Outlet in case condition is false
	Point Corner; //corner of the block

	void UpdateStatementText();

public:
	Condition(Point corner, string left,string compop, string right, bool isval);

	void setLHS(const string& left);
	void setCompOp(const string& compop);
	void setRHS(const string& right);

	void Draw(Output* pOut) const;
	virtual bool InStatement(Point p);
};
#endif

