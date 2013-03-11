#ifndef INSTALLATION_H
#define INSTALLATION_H

#include "radiator.h"
#include "cauldron.h"

/*dilwsei tis klasis Cauldron aka kazani*/
class Installation
{
	/*private metavlites prosvasimes mono apo tin klasi kazani*/
	private:
		int m_external_temp, m_total_consumption, m_system_time;
		Cauldron *kazani;
		Radiator *kalorifer[2];

	public:
		/*public constructor xwris orismata. Xrisimopoiei default epiloges*/
		Installation();

		Installation(int temp, int capacity, int oil, int k_val1, int inter_temp1,int k_val2, int inter_temp2);


		/* Medothoi: Prosferoun pliri leitourgikotita panw stin klassi tou kalorifer.
		 * oi perissoteres orizontai sto arxeio radiator.cpp.
		 * Kapoies methodoi pou den exoun logiki simasia den exoun oristei opws px i dinatotita na pigainei
		 * o xronos pros ta piso, i na to na ginetai set stin katanalwsi klp
		 */

		void calculateAndSetTotalConsumtion(void);

		int getTotalConsumption(void){return m_total_consumption;}

		int getSystemHours(void){return m_system_time;}

		int getExtTemp(void){return m_external_temp;}

		void goOneHourLater(void);

		void setStatus(int status, int kalorifer_id);

		void setExtTemp(int temp);

		void setIntTemp(int temp, int kalorifer_id);

		void increaseExtTemp(int temp);

		void decreaseExtTemp(int temp);

		void increaseIntTemp(int temp, int kalorifer_id);

		void decreaseIntTemp(int temp, int kalorifer_id);

		void fillKazani(int oil);

		void decreaseKazaniOil(int oil);
	
		int getKazaniOil(void);

		void printInstallationSettings(void);



};

#endif

