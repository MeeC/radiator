#include "globals.h"
#include "cauldron.h"

Cauldron::Cauldron(int capacity, int oil)
{
	m_capacity=capacity;
	/*ginetai elegxos an to petrailaio einai perissotero ap tin xwritikotita*/
	if(oil>capacity)m_oil=capacity;
	else m_oil=oil;
}


void Cauldron::addOil(int oil)
{
	m_oil+=oil;
	/*elegxos an kseperase to petrailaio tin xoritikotita*/
	if(m_oil>m_capacity)m_oil=m_capacity;
}

void Cauldron::removeOil(int oil)
{
	m_oil-=oil;
	/*elegxos an kseperase to petrailaio tin xoritikotita*/
	if(m_oil<0)m_oil=0;
}


bool Cauldron::isEmpty(void)
{
	if(m_oil==0)return true; 
	else return false;
}


bool Cauldron::isFull(void)
{
	if(m_oil==m_capacity)return true; 
	else return false;
}

void Cauldron::printStatus(void)
{
	cout<<"XORITIKOTHTA: "<<m_capacity<<endl;
	cout<<"PETRELAIO: "<<m_oil<<endl;

}
