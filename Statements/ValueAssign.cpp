#include "ValueAssign.h"
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

ValueAssign::ValueAssign(Point Lcorner, string LeftHS, double RightHS)
{
	// Note: The LeftHS and RightHS should be validated inside (AddValueAssign) action
	//       before passing it to the constructor of ValueAssign
	LHS = LeftHS;
	RHS = RightHS;

	UpdateStatementText();

	LeftCorner = Lcorner;
	
	pOutConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;	
}


void ValueAssign::setLHS(const string &L)
{
	LHS = L;
	UpdateStatementText();
}

void ValueAssign::setRHS(double R)
{
	RHS = R;
	UpdateStatementText();
}


void ValueAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}

bool ValueAssign::InStatement(Point p)
{
	if (p.x >= LeftCorner.x && p.x <= LeftCorner.x + UI.ASSGN_WDTH && p.y >= LeftCorner.y && p.y <= LeftCorner.y + UI.ASSGN_HI) {
		return true;
}
	return false;
}

void ValueAssign::Save(ofstream& OutFile)
{
	OutFile << 3 << " " << ID << " " << LeftCorner.x << " " << LeftCorner.y << " " << LHS << " " << RHS << endl;
}

void ValueAssign::Load(ifstream& Infile)
{
	Infile >> ID >> LeftCorner.x >> LeftCorner.y >> LHS >> RHS;
	UpdateStatementText();
}

Point ValueAssign::getInlet()
{
	return Inlet;
}

Point ValueAssign::getOutlet()
{
	return Outlet;
}


//This function should be called when LHS or RHS changes
void ValueAssign::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T<<LHS<<" = "<<RHS;	
	Text = T.str();	 
}