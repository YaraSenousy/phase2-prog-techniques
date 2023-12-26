#ifndef READ_H
#define READ_H
#include "Statements/Statement.h"

class Read : public Statement
{
private:
	string VarName; //Variable name 
	Connector* pOutConn; //Read has one connector
	Point Leftcorner; //Left corner of the read block
	void UpdateStatementText();

public:
	Read(Point Lcorner, string varName);
	void setVarName(const string& var);
	void Draw(Output* pOut) const;
	virtual bool InStatement(Point p);
};

#endif