#include "Connector.h"
#include "statements/Statement.h"
Connector::Connector(Statement* Src, Statement* Dst,int branchtype)	
//When a connector is created, it must have a source statement and a destination statement
//There are NO FREE connectors in the flowchart
{
	
	SrcStat = Src;
	DstStat = Dst;

	Selected = false; //not higlighted by default
	Outlet_branch = branchtype; //1 if yes branch, 2 if No otherwise 0

}

void Connector::setSrcStat(Statement *Src)
{	SrcStat = Src;	}

Statement* Connector::getSrcStat()
{	return SrcStat;	}

void Connector::setDstStat(Statement *Dst)
{	DstStat = Dst;	}

Statement* Connector::getDstStat()
{	return DstStat;	}


void Connector::setStartPoint(Point P)
{	Start = P;	}

Point Connector::getStartPoint()
{	return Start;	}

void Connector::setEndPoint(Point P)
{	End = P;	}

Point Connector::getEndPoint()
{	return End;	}

void Connector::Draw(Output* pOut) const
{
	///TODO: Call Output to draw a connector from SrcStat to DstStat on the output window
	//setStartPoint(SrcStat->getOutlet()); 
	//setEndPoint(DstStat->getInlet());
	pOut->DrawConnector(Start, End, Selected);
}

bool Connector::IsConnector(Point p)
{

	if ((p.y <= Start.y+5) && (p.y >= Start.y - 5) && (p.x > Start.x) && (p.x < End.x)) {
	//check if the p is within the lines of the connector
	
		return true;
	}
	else if ((p.x <= End.x + 5) &&(p.x >= End.x - 5) && (p.y > Start.y) && (p.y < End.y))
		return true;
	else
		return false;
}

void Connector::Save(ofstream& OutFile)
{
	OutFile << SrcStat->GetID() << " " << DstStat->GetID() << " " << Outlet_branch << endl;
}
