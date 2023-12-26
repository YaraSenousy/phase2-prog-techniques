#include "Start.h"
#include <sstream>

using namespace std;

Start::Start(Point Lcorner)
{

	
	LeftCorner = Lcorner;

	pOutConn = NULL;  //No connectors yet
	Inlet.x == -1;  // make sure start isnt destination statement
	Outlet.x = LeftCorner.x + UI.START_WDTH / 2;
	Outlet.y = LeftCorner.y + UI.START_HI;
}

void Start::Draw(Output* pOut) const
{
	//Call Output::DrawStart function to draw Start  	
	pOut->DrawStart(LeftCorner, UI.START_WDTH, UI.START_HI, Selected);
}

bool Start::InStatement(Point p)
{
	if (p.x >= LeftCorner.x && p.x <= LeftCorner.x + UI.START_WDTH && p.y >= LeftCorner.y && p.y <= LeftCorner.y + UI.START_HI) {
		return true;
}
	return false;
}

void Start::UpdateStatementText()
{}

