#include "globals.h"
#include "radiator.h"


Radiator::Radiator(int status,int k_value, int ext_t, int intern_t)
{
	if(status==OPEN)
	{
		m_status=OPEN;
		m_k_value=k_value;
		m_external_temp=ext_t;
		m_internal_temp=intern_t;
		m_time=0;
		m_work_time=0;
		m_same_temp_time=0;
		if(ext_t<intern_t)
		{
			m_consumption= k_value*(intern_t-ext_t);
		}
		else
		{
			m_consumption=0;
			m_status=CLOSED;
		}
	}

}

void Radiator::calculateAndSetConsumption(void)
{
	if(m_external_temp<m_internal_temp && m_status==OPEN)
	{
		m_consumption= m_k_value*(m_internal_temp-m_external_temp);
	}
	else
	{
		m_consumption=0;
		m_status=CLOSED;
	}
}
	
void Radiator::goOneHourLater(void)
{
	m_time++;
	if(m_status==OPEN)
	{
		m_work_time++; 
		m_same_temp_time++;
		if((m_consumption)>40)increaseExtTemp(5);
		else if((m_consumption)>30)increaseExtTemp(4);
		else if((m_consumption)>10)increaseExtTemp(3);
		else if((m_consumption)>0)increaseExtTemp(1);
		calculateAndSetConsumption();
	}
	else if(m_status==CLOSED)
	{
		decreaseExtTemp(2);
	}

}
	

void Radiator::setStatus(int status)
{
	if(status==CLOSED)
	{
		m_consumption=0;
		m_status=CLOSED;
	}
	else if(status==OPEN)
	{
		m_status=OPEN;
		calculateAndSetConsumption();
		
	}
}
	

void Radiator::setExtTemp(int temp)
{
	m_external_temp=temp;
	calculateAndSetConsumption();
}
	

void Radiator::setIntTemp(int temp)
{
	m_internal_temp=temp;
	calculateAndSetConsumption();
	m_same_temp_time=0;
}
	
	
void Radiator::increaseExtTemp(int temp)
{
	m_external_temp+=temp;
	calculateAndSetConsumption();
}
	

void Radiator::decreaseExtTemp(int temp)
{
	m_external_temp-=temp;
	calculateAndSetConsumption();
}
	

void Radiator::increaseIntTemp(int temp)
{
	m_internal_temp+=temp;
	calculateAndSetConsumption();
	m_same_temp_time=0;
}
	

void Radiator::decreaseIntTemp(int temp)
{
	m_internal_temp-=temp;
	calculateAndSetConsumption();
	m_same_temp_time=0;
}
	
void Radiator::printRadiatorSettings(void)
{ 
	string str;

	if(m_status==CLOSED)str="KLEISTO";
	else if(m_status==OPEN) str="ANOIXTO";
	cout<<"KATASTASH KALORIFER: "<<str<<endl;
	cout<<"EKSOTERIKH THERMOKRASIA: "<<m_external_temp<<endl;
	cout<<"ESOTERIKH THERMOKRASIA: "<<m_internal_temp<<endl;
	cout<<"KATANALOSH LT/WRA: "<<m_consumption<<endl;
	cout<<"WRES APO THN EKKINHSH TOY SYSTHMATOS: "<<m_time<<endl;
	cout<<"WRES LEITOURGIAS TOY KALORIFER: "<<m_work_time<<endl;
	cout<<"WRES LEITOURGIAS SE AYTH THN RYTHMISH: "<<m_same_temp_time<<endl;
}








