#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1200;
	UI.height = 620;
	UI.wx = 15;
	UI.wy =15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 62;
	UI.DrawingAreaWidth = 0.75 * UI.width;

	UI.DrawColor = BLUE;
	UI.HighlightColor = RED;
	UI.MsgColor = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;
	UI.START_WDTH = 100;
	UI.START_HI = 50;
	UI.IO_WDTH = 120;
	UI.IO_HI = 50;
	UI.COND_WIDTH = 150;
	UI.COND_HI = 100;
	

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");
	
	pWind->SetPen(RED,3);
	CreateDesignToolBar();
	CreateStatusBar();
	ClearDrawArea();
	ClearOutputBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateDesignToolBar() //Draws the Design Menu
{
	UI.AppMode = DESIGN;	//Design Mode
	//clearing the toolbar before drawing the design toolbar
	ClearToolBar();
	//fill the tool bar 
		
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in Defs.h ==> enum DrawMenuItem
	string MenuItemImages[DSN_ITM_CNT];
	MenuItemImages[ITM_SWTICHTOSIM] = "images\\switchtosim.jpg";
	MenuItemImages[ITM_START] = "images\\start.jpg";
	MenuItemImages[ITM_END] = "images\\end.jpg";
	MenuItemImages[ITM_VALUE_ASSIGN] = "images\\value_assign.jpg";
	MenuItemImages[ITM_VARIABLE_ASSIGN] = "images\\var_assign.jpg";
	MenuItemImages[ITM_OPER_ASSIGN] = "images\\oper_assign.jpg";
	MenuItemImages[ITM_COND] = "images\\Condition1.jpg";
	MenuItemImages[ITM_INPUT] = "images\\Read.jpg";
	MenuItemImages[ITM_OUTPUT] = "images\\Write.jpg";
	MenuItemImages[ITM_CONNECTOR] = "images\\connector.jpg";
	MenuItemImages[ITM_SELECT] = "images\\select.jpg";
	MenuItemImages[ITM_COPY] = "images\\copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\paste.jpg";
	MenuItemImages[ITM_DELETE] = "images\\delete.jpg";
	MenuItemImages[ITM_SAVE] = "images\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\load.jpg";
	MenuItemImages[ITM_EDIT] = "images\\edit.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Exit1.jpg";
	//TODO: Prepare images for each menu item and add it to the list


	//Draw menu item one image at a time
	for(int i=0; i<DSN_ITM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateSimulationToolBar() //Draws the Simulation Menu
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	///TODO: add code to create the simulation tool bar
	//clearing the toolbar before drawing the simulation toolbar
	ClearToolBar();
	string SimItemImages[SIM_ITM_CNT];
	SimItemImages[ITM_SWTICHTODESIGN] = "images\\switchtodesign.jpg";
	SimItemImages[ITM_VALIDATE] = "images\\validate.jpg";
	SimItemImages[ITM_RUN] = "images\\run.jpg";
	//Draw simulation toolbar items one image at a time
	for (int i = 0; i < SIM_ITM_CNT; i++)
		pWind->DrawImage(SimItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.DrawingAreaWidth, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearOutputBar()
{
	//Create output bar by drawing a filled rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(LIGHTBLUE);
	pWind->DrawRectangle(UI.DrawingAreaWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() {
	//Create toolbar by drawing a filled rectangle
	pWind->SetPen(WHITE, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0,UI.width , UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int) (UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawString(const int iX, const int iY, const string Text)
{
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(iX, iY, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////

//======================================================================================//
//								Statements Drawing Functions							//
//======================================================================================//


//////////////////////////////////////////////////////////////////////////////////////////
//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 8, Left.y + height / 4, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Add similar functions for drawing all other statements.
//		e.g. DrawCondtionalStat(......), DrawStart(......), DrawEnd(.......), ...etc
//		Decide the parameters that should be passed to each of them
//////////////////////////////////////////////////////////////////////////////////////////
//Draw start statement
void Output::DrawStart(Point left, int width, int height, bool selected)
{
	string Text = "Start";
	if (selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block elipse
	pWind->DrawEllipse(left.x, left.y, left.x + width , left.y + height);
	
	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(left.x + width / 3.5, left.y + height / 3.14, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draw end statement
void Output::DrawEnd(Point left, int width, int height, bool selected)
{
	string Text = "End";
	if (selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block elipse
	pWind->DrawEllipse(left.x, left.y, left.x + width, left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(left.x + width / 3.5, left.y + height / 3.14, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draw read statement
void Output::DrawRead(Point left, int width, int height, string Text, bool selected)
{
	if (selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color
	//Initiate 2 arrays of coordiantes to draw parallelogram
	const int ipX[] = { left.x, left.x + width, left.x + 0.75*width, left.x -0.25*width};
	const int ipY[] = {left.y, left.y,left.y+height, left.y +height};
	const int vert = 4;
	//Draw the statement block paralellogram
	pWind -> DrawPolygon(ipX,ipY,vert);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(left.x, left.y, "Read ");
	pWind->DrawString(left.x, left.y + height / 2, Text);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draw write statement
void Output::DrawWrite(Point left, int width, int height, string Text, bool selected)
{
	if (selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color
	//Initiate 2 arrays of coordiantes to draw parallelogram
	const int ipX[] = { left.x, left.x + width, left.x + 0.75 * width, left.x - 0.25 * width };
	const int ipY[] = { left.y, left.y,left.y + height, left.y + height };
	const int vert = 4;
	//Draw the statement block paralellogram
	pWind->DrawPolygon(ipX, ipY, vert);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(left.x, left.y, "Write ");
	pWind->DrawString(left.x, left.y + height / 2, Text);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draw condition statement
void Output::DrawCondition(Point left, int width, int height, string Text, bool selected) {
	if (selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color
	//Initiate 2 arrays of coordiantes to draw condition
	const int ipX[] = { left.x,left.x + width/2, left.x + width, left.x + width/2};
	const int ipY[] = { left.y, left.y + height,left.y,left.y - height};
	const int vert = 4;
	//Draw statement for condition
	pWind->DrawPolygon(ipX, ipY, vert);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(left.x +width/2, left.y - 0.75*height,"If ");
	pWind->DrawString(left.x+20, left.y -height/3, Text);
	pWind->DrawString(left.x + width*1.05, left.y*0.92, " Yes");
	pWind->DrawString(left.x*0.90, left.y*0.92, "  No");
}


//TODO: Add DrawConnector function

void Output::DrawConnector(Point start, Point end, bool Selected)
{
	if (Selected) {	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
		pWind->SetBrush(UI.HighlightColor);    //to fill the tip of the arrow
	}
	else {
		pWind->SetPen(UI.DrawColor, 3);	//use normal color
		pWind->SetBrush(UI.DrawColor);  //to fill the tip of the arrow
	}

	int x1 = start.x; int y1 = start.y; 
	int x2 = end.x; int y2 = end.y;
	//draw the body of the arrow (the arrow will move horizontally then vertically)
	pWind->DrawLine(x1, y1, x2, y1);
	pWind->DrawLine(x2, y1, x2, y2);
	
	int arrowTip = 6; //the tip of the arrow dimension
	//drawing the tip of the arrow
	if (y1 == y2 && x2 > x1) {
		//pointing to the right
		pWind->DrawTriangle(x2, y2, x2 - arrowTip, y2 + arrowTip, x2 - arrowTip, y2 - arrowTip);
	}
	else if (y1 == y2 && x1 > x2) {
		//pointing to the left
		pWind->DrawTriangle(x2, y2, x2 + arrowTip, y2 + arrowTip, x2 + arrowTip, y2 - arrowTip);
	}
	else if (y2 > y1) {
		//pointing upward
		pWind->DrawTriangle(x2, y2, x2 - arrowTip, y2 - arrowTip, x2 + arrowTip, y2 - arrowTip);
	}
	else {
		//pointing downward
		pWind->DrawTriangle(x2, y2, x2 - arrowTip, y2 + arrowTip, x2 + arrowTip, y2 + arrowTip);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
