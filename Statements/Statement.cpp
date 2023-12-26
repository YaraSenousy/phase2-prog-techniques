#include "Statement.h"

int Statement::count = 0;
Statement::Statement()	
{ 
	//TODO: set the ID with a unique value
	count++;
	ID = count;
	Text = "";
	Selected = false;	
}

void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }


Point Statement::getInlet()
{
	return Inlet;
}

Point Statement::getOutlet()
{
	return Outlet;
}

int Statement::GetID()
{
	return ID;
}

