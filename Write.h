#ifndef WRITE_H
#define WRITE_H
#include "Statements/Statement.h"
class Write : public Statement
{
private:
	string VarName; //Variable name
	Connector* pOutConn; //Connector
	Point Inlet; //Point where last connector ended
	Point Outlet; //Start of next connector
	Point Leftcorner; //Left corner of the read block
	void UpdateStatementText();

public:
	Write(Point Lcorner, string varName);
	void setVarName(const string& var);
	void Draw(Output* pOut) const;
};

#endif
