#include "Start.h"
#include <sstream>

using namespace std;

Start::Start(Point Lcorner)
{

	UpdateStatementText();
	LeftCorner = Lcorner;

	pOutConn = NULL;

	Outlet.x = LeftCorner.x + UI.START_WDTH / 2;
	Outlet.y = LeftCorner.y + UI.START_HI;
}

void Start::Draw(Output* pOut) const
{
	//Call Output::DrawStart function to draw Start  	
	pOut->DrawStart(LeftCorner, UI.START_WDTH, UI.START_HI, Selected);
}

void Start::UpdateStatementText()
{}

