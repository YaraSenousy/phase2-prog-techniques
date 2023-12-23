
#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(Point &P) const
{
	pWind->WaitMouseClick(P.x, P.y);	//Wait for mouse click
}

string Input::GetString(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
double Input::GetValue(Output* pO) const	// Reads a double value from the user 
{
	///TODO: add code to read a double value from the user and assign it to D

	double D = 0;
		
	//This function should make any needed validations on the entered text 
	// to make sure it is a double value (e.g. 12.5, -12.5, -23, -23., -23.0 …etc.).

	
	//Read a string from the user
	string input = GetString(pO);   
	//loop until it is a valid doubel value
	while (IsValue(input) == false) {
		pO->PrintMessage("Invalid double value, Please try agian");
		input = GetString(pO);
	}
	//convert from string to double
	D = stod(input);
	return D;
}
//////////////////////////////////////////////////////////////////////////////////////////
string Input::GetVariable(Output* pO) const	// Reads a variable name from the user 
{
	//get string from user
	string input = GetString(pO);
	//loop until user enters a valid variable name
	while (IsVariable(input) == false) {
		pO->PrintMessage("Invalid variable name, Please try agian");
		input = GetString(pO);
	}
	return input;
}
//////////////////////////////////////////////////////////////////////////////////////////
string Input::GetArithOperator(Output* pO) const  	// Reads an arithmetic operator from the user 
{
	string input;
	bool invalid = true;
	do
	{
		input = GetString(pO);
		//check that only one character is entered 
		if (input.length() == 1) {
			//check that it is *,+,- or /
			if (input[0] == 42 || input[0] == 43 || input[0] == 45 || input[0] == 47) {
				invalid = false;
			}
		}

		//prints a validation message
		if (invalid) {
			pO->PrintMessage("invalid arthimetic operation (*,+,-,/) Please try agian");
		}
	} while (invalid);
	return input;
}
//////////////////////////////////////////////////////////////////////////////////////////
string Input::GetCompOperator(Output* pO) const  // Reads a comparing operator0 from the user
{
	string input;
	bool invalid = true;
	do {
		input = GetString(pO);
		//checking if the input is one character 
		if (input.length() == 1) {
			// if it is < or > then valid (invalid = false)
			if (input[0] == 60 || input[0] == 62) {
				invalid = false;
			}
		}
		//checking if it is two characters and the second character is =
		else if (input.length() == 2 && input[1] == 61) {
			// check that the first charachter is =,!,< or >
			if (input[0] == 61 || input[0] == 33 || input[0] == 60 || input[0] == 62) { 
				invalid = false;
			}
		}
		//validation message
		if (invalid) {
			pO->PrintMessage("Invalid comparison operation (<,>,<=,>=,==,!=) Please try again");
		}
	} while (invalid);
	return input;
}
//////////////////////////////////////////////////////////////////////////////////////////
ActionType Input::GetUserAction() const
{	
	//This function reads the position where the user clicks to determine the desired action

	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{
			case ITM_VALUE_ASSIGN: return ADD_VALUE_ASSIGN;
			case ITM_COND: return ADD_CONDITION;
			case ITM_EXIT: return EXIT;	
			case ITM_COPY: return COPY;
			case ITM_SWTICHTOSIM: return SWITCH_SIM_MODE;
			case ITM_START: return ADD_START;
			case ITM_END: return ADD_END;
			case ITM_INPUT: return ADD_READ;
			case ITM_OUTPUT:return ADD_WRITE;
			case ITM_CONNECTOR:return ADD_CONNECTOR;
			case ITM_PASTE:return PASTE;
			case ITM_DELETE:return DEL;
			case ITM_SAVE:return SAVE;
			case ITM_LOAD:return LOAD;
			case ITM_VARIABLE_ASSIGN: return ADD_VAR_ASSIGN;
			case ITM_OPER_ASSIGN: return ADD_OPER_ASSIGN;
			case ITM_SELECT: return SELECT;
			case ITM_CUT: return CUT;
			case ITM_EDIT: return EDIT_STAT;
					
			default: return DSN_TOOL;
			}
		}
	
		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			if (x <= UI.DrawingAreaWidth)
				return DRAWING_AREA;	
			else
				return OUTPUT_AREA;
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//Application is in Simulation mode
	{

		// TODO: This should be changed after creating the compelete simulation bar 
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = (x / UI.MenuItemWidth);
			switch (ClickedItem) {
				//simulation items
			case ITM_SWTICHTODESIGN: return SWITCH_DSN_MODE;
			case ITM_VALIDATE: return VALIDATE;
			case ITM_RUN: return RUN;

			}
		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			if (x <= UI.DrawingAreaWidth)
				return DRAWING_AREA;
			else
				return OUTPUT_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}

}


Input::~Input()
{
}
