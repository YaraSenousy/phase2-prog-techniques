#include "Condition.h"
#include <sstream>
#include <fstream>


Condition::Condition(Point corner,string left,string compop, string right, bool isval)
{
	LHS = left;
	CompOp = compop;
	RHS = right;
	UpdateStatementText();
	Corner = corner;

	pOutConnYes = NULL; //no connector yet
	pOutConnNo = NULL; //no connector yet

	//need to change after connector draw is added
	Inlet.x = Corner.x + UI.ASSGN_WDTH / 2; 
	Inlet.y = Corner.y;

	OutletYes.x = Corner.x;
	OutletYes.y = Corner.y + UI.ASSGN_HI;

	OutletNo.x = Corner.x - UI.ASSGN_WDTH / 2;
	OutletNo.y = Corner.y + UI.ASSGN_HI;
}

void Condition::UpdateStatementText()
{
	//Build statement text: LHS variable then comparison operator then RHS variable/value
	ostringstream T;
	T << LHS << " " << CompOp << " " << RHS;
	Text = T.str();
}


void Condition::setLHS(const string& left)
{
	LHS = left;
	UpdateStatementText();
}

void Condition::setCompOp(const string& compop)
{
	CompOp = compop;
	UpdateStatementText();
}

void Condition::setRHS(const string& right)
{
	RHS = right;
	UpdateStatementText();
}

void Condition::Draw(Output* pOut) const
{
	pOut->DrawCondition(Corner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}

bool Condition::InStatement(Point p)
{
	if (p.x >= Corner.x && p.x <= Corner.x + UI.ASSGN_WDTH && p.y >= Corner.y && p.y <= Corner.y + UI.ASSGN_HI) {
		return true;
	}
	return false;
}

void Condition::Save(ofstream& OutFile)
{
	OutFile << "COND" << " " << ID << " " << LHS << " " << CompOp << " " << RHS << endl;
}
