#include "Condition.h"
#include <sstream>
#include <fstream>


Condition::Condition(Point corner,string left,string compop, string right, bool isval)
{
	check = 2;
	LHS = left;
	CompOp = compop;
	RHS = right;
	UpdateStatementText();
	Corner = corner;

	pOutConnYes = NULL; //no connector yet
	pOutConnNo = NULL; //no connector yet

	Inlet.x = Corner.x + UI.COND_WIDTH /2; 
	Inlet.y = Corner.y - UI.COND_HI/2;

	OutletYes.x = Corner.x + UI.COND_WIDTH;
	OutletYes.y = Corner.y;

	OutletNo.x = Corner.x;
	OutletNo.y = Corner.y;
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
	if (p.x >= Corner.x && p.x <= Corner.x + UI.COND_WIDTH && p.y >= Corner.y - UI.COND_HI/2 && p.y <= Corner.y + UI.COND_HI/2) {
		return true;
	}
	return false;
}


void Condition::Save(ofstream& OutFile)
{
	OutFile << 6 << " " << ID << " "<< Corner.x << " " << Corner.y << " " << LHS << " " << CompOp << " " << RHS << endl;
}

void Condition::Load(ifstream& Infile)
{
	Infile >> ID >>Corner.x>>Corner.y >> LHS >> CompOp >> RHS;
	Inlet.x = Corner.x + UI.COND_WIDTH / 2;
	Inlet.y = Corner.y - UI.COND_HI / 2;

	OutletYes.x = Corner.x + UI.COND_WIDTH;
	OutletYes.y = Corner.y;

	OutletNo.x = Corner.x;
	OutletNo.y = Corner.y;
	UpdateStatementText();
}

Point Condition::getOutlet_yesOrno(int branchtype)
{
	if (branchtype == 1) {
		return OutletYes;
	}
	else
		return OutletNo;
}

Connector* Condition::getpConnOut(int branchtype)
{
	if (branchtype == 1)
		return pOutConnYes;
	else
		return pOutConnNo;
}

void Condition::SetpConnOut(Connector* conn, int branchtype)
{
	if (branchtype == 1)
		pOutConnYes = conn;
	else
		pOutConnNo = conn;
}

