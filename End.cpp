#include "End.h"

#include <sstream>
#include <fstream>

using namespace std;

End::End(Point Lcorner)
{

	LeftCorner = Lcorner;
	Inlet.x = LeftCorner.x + UI.START_WDTH / 2;
	Inlet.y = LeftCorner.y;
}

void End::Draw(Output* pOut) const
{
	//Call Output::DrawEnd function to draw End  	
	pOut->DrawEnd(LeftCorner, UI.START_WDTH, UI.START_HI, Selected);
}

bool End::InStatement(Point p)
{
	if (p.x >= LeftCorner.x && p.x <= LeftCorner.x + UI.START_WDTH && p.y >= LeftCorner.y && p.y <= LeftCorner.y + UI.START_HI) {
		return true;
	}
	return false;
}

void End::Save(ofstream& OutFile)
{
	OutFile << 2 << " " << ID << " " << LeftCorner.x << " " << LeftCorner.y << endl;
}

void End::Load(ifstream& Infile)
{
	Infile >> ID >> LeftCorner.x >> LeftCorner.y;
	Inlet.x = LeftCorner.x + UI.START_WDTH / 2;
	Inlet.y = LeftCorner.y;
	UpdateStatementText();
}

void End::UpdateStatementText()
{}

