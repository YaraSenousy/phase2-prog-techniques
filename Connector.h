#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "GUI\UI_Info.h"
#include "GUI\output.h"
#include <fstream>
#include "ApplicationManager.h"
class Statement;

class Connector	//a connector that connects two statements (Source & Destination)
{
private:
	Statement *SrcStat;	//The source statement of the connector
	Statement *DstStat;	//The destination statement of the connector
	Point Start;	//Start point of the connector
	Point End;		//End point of the connector
	int Outlet_branch; //for conditonal statements 1:YES 2:No 3:otherwisw

	bool Selected; // true if the connector is selected 
public:
	Connector(Statement* Src = nullptr, Statement* Dst = nullptr, int branchtype = 0);

	void		setSrcStat(Statement *Src);
	Statement*	getSrcStat();	
	void		setDstStat(Statement *Dst);
	Statement*	getDstStat();

	void setStartPoint(Point P);
	Point getStartPoint();

	void setEndPoint(Point P);
	Point getEndPoint();

	void Draw(Output* pOut) const;
	bool InConnector(Point p);
	bool IsSelected();
	void Save(ofstream& OutFile);
	//void load(ifstream& Infile,ApplicationManager* pManager);
	void SetSelected(bool s);
};

#endif