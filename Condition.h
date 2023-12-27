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

	Connector* pOutConnYes; //first connector in case condition is true
	Connector* pOutConnNo; //second connector in case condition false
	Point OutletYes; //outlet in case condition is true
	Point OutletNo; //Outlet in case condition is false
	Point Corner; //corner of the block

	void UpdateStatementText();

public:
	Condition(Point corner = Point(-1,-1), string left = "", string compop = "", string right = "", bool isval = false);

	void setLHS(const string& left);
	void setCompOp(const string& compop);
	void setRHS(const string& right);

	void Draw(Output* pOut) const;
	virtual bool InStatement(Point p);

	virtual void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	Point getOutlet_yesOrno(int branchtype);
	virtual Point getOutlet(int branchtype);
};
#endif

