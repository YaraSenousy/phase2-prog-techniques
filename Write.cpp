#include "Write.h"
#include "GUI/UI_Info.h"
#include <sstream>
#include <fstream>

Write::Write(Point Lcorner, string varName)
{
	//set variabla name
	VarOrString = varName;
	UpdateStatementText();

	Leftcorner = Lcorner;
	pOutConn = NULL; //No connector yet

	Inlet.x = Leftcorner.x + UI.IO_WDTH / 2;
	Inlet.y = Leftcorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = Leftcorner.y + UI.IO_HI;
}

void Write::setVarName(const string& var)
{
	VarOrString = var;
	UpdateStatementText();
}

void Write::Draw(Output* pOut) const
{
	//Call Output::DrawRead to draw read statement
	pOut->DrawWrite(Leftcorner, UI.IO_WDTH, UI.IO_HI, Text, Selected);
}

bool Write::InStatement(Point p)
{
	if (p.x >= Leftcorner.x && p.x <= Leftcorner.x + UI.IO_WDTH && p.y >= Leftcorner.y && p.y <= Leftcorner.y + UI.IO_HI) {
		return true;
	}
	return false;
}

void Write::Save(ofstream& OutFile)
{
	OutFile << 8 << " " << ID << " " << Leftcorner.x << " " << Leftcorner.y << " " << VarOrString << endl;
}

void Write::Load(ifstream& Infile)
{
	Infile >> ID >> Leftcorner.x >> Leftcorner.y >> VarOrString;
	UpdateStatementText();
}

void Write::UpdateStatementText() {
	ostringstream T;
	T << VarOrString;
	Text = T.str();
}