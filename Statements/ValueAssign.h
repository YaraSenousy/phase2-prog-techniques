#ifndef VALUE_ASSIGN_H
#define VALUE_ASSIGN_H

#include "Statement.h"

//Value Assignment statement class
//The value assignment statement assigns a value to a variable
class ValueAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	double RHS;	//Right Handside (Value)
	
	Connector *pOutConn;	//Value Assignment Stat. has one Connector to next statement
	                        //Each statement type in flowchart has a predefined number of (output) connectors
	                        //For example, conditional statement always has 2 output connectors

	                        //Note: We don't need to keep track with input connectors
	                        //      Whenever we want to iterate on all statements of the flowchart
	                        //      we will begin with start statement then its output connector
	                        //      then the connector's destination statement and so on (follow the connectors)

	

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();
	
public:
	ValueAssign(Point Lcorner=Point(-1,-1), string LeftHS = "", double RightHS = 0);
	
	void setLHS(const string &L);
	void setRHS(double R);

	virtual void Draw(Output* pOut) const;
	virtual bool InStatement(Point p);
	virtual void Save(ofstream& OutFile);
	void Load(ifstream& Infile);

	Point getInlet();
	Point getOutlet();
};

#endif