#include "Write.h"
#include "GUI/UI_Info.h"
#include <sstream>

Write::Write(Point Lcorner, string varName)
{
	//set variabla name
	VarName = varName;
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
	VarName = var;
	UpdateStatementText();
}

void Write::Draw(Output* pOut) const
{
	//Call Output::DrawRead to draw read statement
	pOut->DrawWrite(Leftcorner, UI.IO_WDTH, UI.IO_HI, Text, Selected);
}

void Write::UpdateStatementText() {
	ostringstream T;
	T << VarName;
	Text = T.str();
}