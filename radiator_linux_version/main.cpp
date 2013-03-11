#include "globals.h"
#include "cauldron.h"
#include "radiator.h"
#include "installation.h"

int main()
{
	
	int input;
	system("clear");
	cout<<"WELCOME TO KALORIFER APPLICATION!!!"<<endl;
	cout<<"ME TOUS ARITHMOUS KAI ENTER EPILEGETE THN LEITOURGIA POU THELETE:\n"<<endl;
	
	do{
	cout<<"1. EKKINHSH TOU SYSTHMATOS ME DEFAULT RITHMISEIS"<<endl;
	cout<<"2. EKKINHSH TOU SYSTHMATOS ME DIKES SAS RITHMISEIS"<<endl;

	cin>>input;
	break;
	cout<<"LATHOS EISODOS: KSANADOKIMASTE!"<<endl;
	}while(input<0 || input>2);

	Installation * sistima; 

	if(input==1)sistima = new Installation();
	else if(input==2)
	{	int temp,capacity,oil,k_val1, inter_temp1, k_val2,inter_temp2;
		
		cout<<"DOSTE EKSOTERIKI THERMOKRASIA:"<<endl;
		cin>>input;
		temp=input;
		cout<<"DOSTE XORITIKOTITA KAZANIOU:"<<endl;
		cin>>input;
		capacity=input;
		cout<<"DOSTE POSOTITA PETRAILAIOY:"<<endl;
		cin>>input;
		oil=input;
		cout<<"DOSTE STATHERA K KALORIFER 1 :"<<endl;
		cin>>input;
		k_val1=input;
		cout<<"DOSTE ESOTERIKI THERMOKRASIA KALORIFER 1:"<<endl;
		cin>>input;
		inter_temp1=input;
		cout<<"DOSTE STATHERA K KALORIFER 2 :"<<endl;
		cin>>input;
		k_val2=input;
		cout<<"DOSTE ESOTERIKI THERMOKRASIA KALORIFER 2:"<<endl;
		cin>>input;
		inter_temp2=input;

		sistima = new Installation(temp,capacity, oil, k_val1, inter_temp1, k_val2, inter_temp2);
	}

	for(;;)
	{
		int oil,temp;
		system("clear");
		sistima->printInstallationSettings();

		cout<<"\nEPILOGES:"<<endl;

		cout<<"1.GO MIA WRA ARGOTERA:"<<endl;

		cout<<"2.PROSTHESH PETRELAIOY STO KAZANI:"<<endl;

		cout<<"3.ALLAGH ESWTERIKHS THERMOKRASIAS TOY KALORIFER 1 :"<<endl;

		cout<<"4.ALLAGH ESWTERIKHS THERMOKRASIAS TOY KALORIFER 2 :"<<endl;

		cout<<"5.ANOIGMA KALORIFER 1 AN EXEI KLEISEI :"<<endl;

		cout<<"6.ANOIGMA KALORIFER 2 AN EXEI KLEISEI :"<<endl;

		cout<<"7.EXODOS"<<endl;		
		
		cin>>input;
		
		switch(input)
		{
			case 1:
				sistima->goOneHourLater();
				break;
			case 2:
				cout<<"PETRELAIO GIA TO KAZANI:"<<endl;
				cin>>oil;
				sistima->fillKazani(oil);
				break;
			case 3:
				cout<<"NEA THERMOKRASIAS KALORIFER 1 :"<<endl;
				cin>>temp;
				sistima->setIntTemp(temp, 1);
				break;
			case 4:
				cout<<"NEA THERMOKRASIAS KALORIFER 2 :"<<endl;
				cin>>temp;
				sistima->setIntTemp(temp, 2);
				break;
			case 5:
				sistima->setStatus(OPEN,1);
				break;
			case 6:
				sistima->setStatus(OPEN,2);
				break;
			case 7:
				exit(0);
		}



	}



}
