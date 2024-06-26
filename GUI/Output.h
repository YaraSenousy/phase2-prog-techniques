#ifndef OUPTUT_H
#define OUPTUT_H

#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();	

	window* CreateWind(int, int, int , int);
	Input* CreateInput(); //Creates a pointer to the Input object	

	void CreateStatusBar(); //Creates status bar

	//TODO: Complete the following 2 functions
	void CreateDesignToolBar();	//Tool bar of the design mode
	void CreateSimulationToolBar(); //Tool bar of the simulation mode

	void ClearStatusBar();	//Clears the status bar
	void ClearDrawArea();	//Clears the drawing area
	void ClearOutputBar(); //Clears the Output bar
	void ClearToolBar(); //Clears the toolbar
	
	void PrintMessage(string msg);	//Prints a message on Status bar
	void DrawString(const int, const int, const string);  //Writes a string in the specified location

	// -- Statements Drawing Functions

	//TODO: Add similar functions for drawing all other statements.
	//		e.g. DrawCondtionalStat(......), DrawStart(......), DrawEnd(.......), ...etc
	//		Decide the parameters that should be passed to each of them
	void DrawStart(Point left, int width, int height, bool selected = false);
	void DrawAssign(Point Left, int width, int height, string Text, bool Selected=false);
	void DrawEnd(Point left, int width, int height, bool selected = false);
	void DrawRead(Point left, int width, int height, string Text = "", bool selected = false);
	void DrawWrite(Point left, int width, int height, string Text = "", bool selected = false);
	void DrawCondition(Point left, int width, int height, string Text = "", bool selected = false);
	
	//TODO: Add DrawConnector function
	void DrawConnector(Point start, Point end, bool Selected = false);
	~Output();
};

#endif