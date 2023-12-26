#include "Action.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

Point Action::PointInDrawing(Input* pIn,Output* pOut)
{
    Point position;
    //takes point from user
    pIn->GetPointClicked(position);
    //validate that it is inside the drawing area
    while (position.x<0 || position.x>UI.DrawingAreaWidth || position.y > UI.height - UI.StatusBarHeight || position.y < UI.ToolBarHeight){
        pOut->PrintMessage("You can only draw inside the drawing area");
        pIn->GetPointClicked(position);
    }
    pOut->ClearStatusBar();
    return position;
}
