#include "VariableAssign.h"
#include <sstream>
#include <fstream>

using namespace std;

VariableAssign::VariableAssign(Point Lcorner, string LeftHS, string RightHS) {
	//Passing LeftHS and RightHS to constructor VariableAssign
	LHS = LeftHS;
	RHS = RightHS;

	UpdateStatementText();

	LeftCorner = Lcorner;

	pOutConn = NULL; //No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;

}

//called when LHS or RHS are changed

void VariableAssign::UpdateStatementText()
{
	//build statement text: LHS = RHS
	ostringstream T;
	T << LHS << " = " << RHS;
	Text = T.str();
}

void VariableAssign::setLHS(const string& L) {
	LHS = L;
	UpdateStatementText();
}

void VariableAssign::setRHS(const string& R) {
	RHS = R;
	UpdateStatementText();
}

void VariableAssign::Draw(Output* pOut) const {
	//Calls Output::DrawAssign function to draw assignment statement
	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}

bool VariableAssign::InStatement(Point p)
{
	if (p.x >= LeftCorner.x && p.x <= LeftCorner.x + UI.ASSGN_WDTH && p.y >= LeftCorner.y && p.y <= LeftCorner.y + UI.ASSGN_HI) {
		return true;
}
	return false;
}

void VariableAssign::Save(ofstream& OutFile)
{
	OutFile << 4 << " " << ID << " " << LeftCorner.x << " " << LeftCorner.y << " " << LHS << " " << RHS << endl;

}

Point VariableAssign::getInlet()
{
	return Inlet;
}

Point VariableAssign::getOutlet()
{
	return Outlet;
}
