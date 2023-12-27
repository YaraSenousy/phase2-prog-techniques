#ifndef WRITE_H
#define WRITE_H
#include "Statements/Statement.h"
class Write : public Statement
{
private:
	string VarOrString; //Variable or sentence to be displayed name
	Connector* pOutConn; //Connector
	Point Leftcorner; //Left corner of the read block
	void UpdateStatementText();

public:
	Write(Point Lcorner = Point(-1,-1), string varName = "");
	void setVarName(const string& var);
	void Draw(Output* pOut) const;
	virtual bool InStatement(Point p);
	virtual void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
};

#endif

