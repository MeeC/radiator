#include "globals.h"
#include "installation.h"

Installation::Installation()
{
	m_external_temp=3;
	kazani=new Cauldron(4000,3500);
	kalorifer[0]=new Radiator(OPEN,2,m_external_temp,25);
	kalorifer[1]=new Radiator(OPEN,3,m_external_temp,21);
	calculateAndSetTotalConsumtion();
	m_system_time=0;
}


Installation::Installation(int temp, int capacity, int oil, int k_val1, int inter_temp1,int k_val2,int inter_temp2)
{
	m_external_temp=temp;
	kazani=new Cauldron(capacity,oil);
	kalorifer[0]=new Radiator(OPEN,k_val1,m_external_temp,inter_temp1);
	kalorifer[1]=new Radiator(OPEN,k_val2,m_external_temp,inter_temp2);
	calculateAndSetTotalConsumtion();
	m_system_time=0;
}

void Installation::fillKazani(int oil)
{
	kazani->addOil(oil);

}

void Installation::decreaseKazaniOil(int oil)
{
	kazani->removeOil(oil);
}

int Installation::getKazaniOil(void)
{
	int oil=kazani->getOil();
	return oil;
}

void Installation::calculateAndSetTotalConsumtion(void)
{
	m_total_consumption=kalorifer[0]->getConsumption()+kalorifer[1]->getConsumption();
}

void Installation::goOneHourLater(void)
{	
	m_system_time++;

	if ((kalorifer[0]->getConsumption()) < getKazaniOil())
	{
		decreaseKazaniOil(kalorifer[0]->getConsumption());
	
		kalorifer[0]->goOneHourLater();
	
		m_external_temp=kalorifer[0]->getExtTemp();

	}
	else setStatus(CLOSED, 1);

	if ((kalorifer[1]->getConsumption()) < getKazaniOil())
	{	
		decreaseKazaniOil(kalorifer[1]->getConsumption());
		kalorifer[1]->goOneHourLater();
		m_external_temp=kalorifer[1]->getExtTemp();
		
	}
	else setStatus(CLOSED, 2);

	calculateAndSetTotalConsumtion();
}
	

void Installation::setStatus(int status, int kalorifer_id)
{
	if(kalorifer_id==1||kalorifer_id==2)
	kalorifer[kalorifer_id-1]->setStatus(status);
	calculateAndSetTotalConsumtion();
}	


	
void Installation::setExtTemp(int temp)
{
	m_external_temp=temp;
	kalorifer[0]->setExtTemp(temp);
	kalorifer[1]->setExtTemp(temp);
	calculateAndSetTotalConsumtion();
}

void Installation::setIntTemp(int temp, int kalorifer_id)
{
	if(kalorifer_id==1||kalorifer_id==2)
	kalorifer[kalorifer_id-1]->setIntTemp(temp);
	calculateAndSetTotalConsumtion();
}

	
void Installation::increaseExtTemp(int temp)
{
	m_external_temp+=temp;
	kalorifer[0]->increaseExtTemp(temp);
	kalorifer[1]->increaseExtTemp(temp);
	calculateAndSetTotalConsumtion();
}
	
void Installation::decreaseExtTemp(int temp)
{
	m_external_temp-=temp;
	kalorifer[0]->decreaseExtTemp(temp);
	kalorifer[1]->decreaseExtTemp(temp);
	calculateAndSetTotalConsumtion();
}	



void Installation::increaseIntTemp(int temp, int kalorifer_id)
{
	if(kalorifer_id==1||kalorifer_id==2)
	kalorifer[kalorifer_id-1]->increaseIntTemp(temp);
	calculateAndSetTotalConsumtion();
}
	

void Installation::decreaseIntTemp(int temp, int kalorifer_id)
{
	if(kalorifer_id==1||kalorifer_id==2)
	kalorifer[kalorifer_id-1]->decreaseIntTemp(temp);
	calculateAndSetTotalConsumtion();
}



	
void Installation::printInstallationSettings(void)
{ 	
	cout<<"\nPLIROFORIES EGKATASTASHS\n"<<endl;
	cout<<"EKSOTERIKH THERMOKRASIA: "<<m_external_temp<<endl;
	cout<<"SYNOLIKH KATANALOSH LT/WRA: "<<m_total_consumption<<endl;
	cout<<"SYNOLIKES WRES LEITOYRGIAS TOY SYSTHMATOS: "<<m_system_time<<endl;

	cout<<"\nPLIROFORIES KAZANI\n"<<endl;
	kazani->printStatus();
	cout<<"\nPLIROFORIES KALORIFER 1\n"<<endl;
	kalorifer[0]->printRadiatorSettings();
	cout<<"\nPLIROFORIES KALORIFER 2\n"<<endl;
	kalorifer[1]->printRadiatorSettings();

}




