#include "End.h"

#include <sstream>

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

void End::UpdateStatementText()
{}
