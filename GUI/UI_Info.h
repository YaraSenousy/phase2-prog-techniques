#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\DEFS.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	MODE AppMode;		//Application Mode (design or simulation)
	
	int width, height;	//Window width and height
	int wx, wy;			//Window starting coordinates

	int StatusBarHeight;	//Status Bar Width
	int ToolBarHeight;		//Tool Bar Width
	int MenuItemWidth;		//Menu Item Width
	int DrawingAreaWidth;   //Drawing Area Width
	
	color DrawColor;		//Drawing color
	color HighlightColor;		//Highlighting color
	color MsgColor;		//Messages color

	int ASSGN_WDTH;		//Assignment statement default width
	int ASSGN_HI;		//Assignment statement default height

	int START_WDTH;  //Start statement default width
	int START_HI;    //Start statement default height

	int IO_WDTH;  //Read & write (input/output) statement defult width 
	int IO_HI;    //Read & write (input/output) statement defult height 

	int COND_WIDTH; //Condition default width
	int COND_HI; //Condition default height
	
}UI;	//create a single global object UI

struct Point	
{
	int x,y;
	Point(int a=0, int b=0)	//constructor
	{ x=a;	y=b;	}
	bool operator==(Point P) {
		if (this->x == P.x && this->y == P.y)
			return true;
		else return false;
	}
};

#endif