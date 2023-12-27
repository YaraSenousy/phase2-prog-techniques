#ifndef STATEMENT_H
#define STATEMENT_H

#include "..\defs.h"
#include "..\Connector.h"
//class Output;
#include "..\GUI\Output.h"

//Base class for all Statements
class Statement
{
protected:
	int ID;			//Each Statement has an ID --> must be unique
	static int count; //used to set a unique ID for each statement
	string Text;	//Statement text (e.g.  "X = 5" OR "salary > 3000" and so on)
	bool Selected;	//true if the statement is selected on the folwchart
	DesignMenuItem stat_type; //stores the type of each statement


	Point Inlet;	//A point where connections enters this statement 
	//It's used as the (End) point of the (Input) connectors
	Point Outlet;	//A point a connection leaves this statement
	//It's used as the (Start) point of the (Output) connector

	virtual void UpdateStatementText() = 0;	//is called when any part of the stat. is edited	

	/// Add more parameters if needed.

public:
	Statement();
	void SetSelected(bool s);
	bool IsSelected() const;

	virtual void Draw(Output* pOut) const  = 0 ;	//Draw the statement
	Point getInlet();
	Point getOutlet();

	///TODO:The following functions should be supported by the Statement class
	///		It should then be overridden by each derived Statement
	///		Decide the parameters that you should pass to each function and its return type

	virtual void Save(ofstream& OutFile) = 0;	//Save the Statement parameters to a file
	virtual void Load(ifstream& Infile) {};	//Load the Statement parameters from a file

	//virtual void Edit() = 0;		//Edit the Statement parameter

	//virtual void Simulate();	//Execute the statement in the simulation mode

	//[BONUS] virtual void GenerateCode(ofstream &OutFile) = 0;	//write the statement code to a file


	///TODO: Add more functions if needed
	virtual bool InStatement(Point p) = 0; //Check if a point is within the statement 


	int GetID();

	
};

#endif