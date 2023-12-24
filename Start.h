#ifndef START_H 
#define START_H

#include "Statements/Statement.h"

//Start Assignment statement class
//The Start assignment statement adds a start statement

class Start : public Statement
{
private:
	
	Connector* pOutConn;     //Start Assignment Stat. has one Connector to next statement
	Point Outlet;           //A point a connection leaves this statement
	Point LeftCorner;       //left corenr of the statement block.

	virtual void UpdateStatementText();

public:
	Start(Point Lcorner);
	virtual void Draw(Output* pOut) const;



};

#endif
