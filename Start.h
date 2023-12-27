#ifndef START_H 
#define START_H

#include "Statements/Statement.h"

//Start Assignment statement class
//The Start assignment statement adds a start statement

class Start : public Statement
{
private:
	
	Connector* pOutConn;     //Start Assignment Stat. has one Connector to next statement
	Point LeftCorner;       //left corenr of the statement block.

	virtual void UpdateStatementText();

public:
	Start(Point Lcorner = Point(-1,-1));
	virtual void Draw(Output* pOut) const;
	virtual bool InStatement(Point p);
	virtual void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
};

#endif
