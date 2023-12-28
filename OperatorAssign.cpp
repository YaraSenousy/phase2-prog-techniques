#include "OperatorAssign.h"
#include <sstream>
#include <fstream>

using namespace std;

OperatorAssign::OperatorAssign(Point Lcorner, string LeftHs, string RightHs1,bool value1, string RightHsO, string RightHs2,bool value2) {
	
	LHS = LeftHs;
	RHS1 = RightHs1;
	isValue1 = value1;
	opp = RightHsO;
	RHS2 = RightHs2;
	isValue2 = value2;

	UpdateStatementText();

	LeftCorner = Lcorner;

	pOutConn = NULL; //No connector yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

//called when LHS, RHS1, opp or RHS2 are changed
void OperatorAssign::UpdateStatementText()
{
	//Build statement text: Left handside then equals then 1st RHS, then opperator, then 2nd RHS
	ostringstream T;
	T << LHS << " = " << RHS1 << " " << opp << " " << RHS2;
	Text = T.str();
}

void OperatorAssign::setLHS(const string& L) {
	LHS = L;
	UpdateStatementText();
}

void OperatorAssign::setRHS1(const string& R1) {
	RHS1 = R1;
	UpdateStatementText();
}

void OperatorAssign::setRHS2(const string& R2) {
	RHS2 = R2;
	UpdateStatementText();
}

void OperatorAssign::setRHSO(const string& RO) {
	opp = RO;
	UpdateStatementText();
}

void OperatorAssign::Draw(Output* pOut) const {
	//calls Output::DrawAssign function to draw assignment statement
	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}

bool OperatorAssign::InStatement(Point p)
{
	if (p.x >= LeftCorner.x && p.x <= LeftCorner.x + UI.ASSGN_WDTH && p.y >= LeftCorner.y && p.y <= LeftCorner.y + UI.ASSGN_HI) {
		return true;
}
	return false;
}

void OperatorAssign::Save(ofstream& OutFile)
{
	OutFile << 5 << " " << ID << " " << LeftCorner.x << " " << LeftCorner.y << " " << LHS << " " << RHS1 << " " << opp << " " << RHS2 << endl;
}

void OperatorAssign::Load(ifstream& Infile)
{
	Infile >> ID >> LeftCorner.x >> LeftCorner.y >> LHS >> RHS1 >> opp >> RHS2;
	UpdateStatementText();
}
