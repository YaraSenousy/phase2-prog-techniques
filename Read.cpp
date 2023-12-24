#include "Read.h"
#include "GUI/UI_Info.h"
#include <sstream>

Read::Read(Point Lcorner, string varName)
{
	//Variable name is validated before being sent to constructor
	VarName = varName;
	UpdateStatementText();

	Leftcorner = Lcorner;
	pOutConn = NULL; //No connector yet

	Inlet.x = Leftcorner.x + UI.IO_WDTH / 2;
	Inlet.y = Leftcorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = Leftcorner.y + UI.IO_HI;
}

void Read::setVarName(const string& var)
{
	VarName = var;
	UpdateStatementText();
}

void Read::Draw(Output* pOut) const
{
	//Call Output::DrawRead to draw read statement
	pOut->DrawRead(Leftcorner, UI.IO_WDTH, UI.IO_HI,Text,Selected);
}
bool Read::InStatement(Point p)
{
	if (p.x >= Leftcorner.x && p.x <= Leftcorner.x + UI.IO_WDTH && p.y >= Leftcorner.y && p.y <= Leftcorner.y + UI.IO_HI) {
		return true;
}
	return false;
}
void Read::UpdateStatementText() {
	ostringstream T;
	T << VarName;
	Text = T.str();
}



