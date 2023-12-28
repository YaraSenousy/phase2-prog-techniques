#include "Statement.h"

int Statement::count = 0;
Statement::Statement()	
{ 
	//TODO: set the ID with a unique value
	count++;
	ID = count;
	Text = "";
	Selected = false;	
	check = 1;
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

Connector* Statement::GetConnOut()
{
	return pOutConn;
}

void Statement::SetpConnOut(Connector* conn)
{
	pOutConn = conn;
}



int Statement::GetID()
{
	return ID;
}

