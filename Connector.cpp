#include "Connector.h"
#include "Condition.h"
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

bool Connector::IsSelected() {

	return Selected;
}

void Connector::SetSelected(bool s) {
	Selected = s;
}

void Connector::setSrcStat(Statement *Src)
{	SrcStat = Src;	}

Statement* Connector::getSrcStat()
{	return SrcStat;	}

void Connector::setDstStat(Statement *Dst)
{	DstStat = Dst;	}

Statement* Connector::getDstStat()
{	return DstStat;	}


void Connector::setStartPoint()
{
	if (Outlet_branch != 0) {  //yes or no branch
		//casting the statement to condition
		Condition* cond = dynamic_cast<Condition*>(SrcStat);
		//setting the start point to draw the connector to Yes or No point
		Start = cond->getOutlet_yesOrno(Outlet_branch);
	}
	else
		Start = SrcStat->getOutlet();
}

Point Connector::getStartPoint()
{	return Start;	}

void Connector::setEndPoint()
{
	End = DstStat->getInlet();
}

Point Connector::getEndPoint()
{	return End;	}

void Connector::Draw(Output* pOut) const
{
	pOut->DrawConnector(Start, End, Selected);
}

bool Connector::InConnector(Point p)
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
