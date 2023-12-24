#ifndef END_H 
#define END_H

#include "Statements/Statement.h"

//End Assignment statement class
//The End assignment statement adds a start statement


class End : public Statement
{
private:
	Point Inlet;           //A point a connection enters this statement
	Point LeftCorner;       //left corenr of the statement block.

	virtual void UpdateStatementText();

public:
	End(Point Lcorner);
	virtual void Draw(Output* pOut) const;


};
#endif
