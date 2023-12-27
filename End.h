#ifndef END_H 
#define END_H

#include "Statements/Statement.h"

//End Assignment statement class
//The End assignment statement adds a start statement


class End : public Statement
{
private:
	Point LeftCorner;       //left corenr of the statement block.

	virtual void UpdateStatementText();

public:
	End(Point Lcorner = Point(-1,-1));
	virtual void Draw(Output* pOut) const;
	virtual bool InStatement(Point p);
	virtual void Save(ofstream& OutFile);
};
#endif
