#ifndef RADIATOR_H
#define RADIATOR_H

/*dilwsei tis klasis Radiator aka kalorifer*/
class Radiator
{
	/*private metavlites prosvasimes mono apo tin klasi kalorifer*/
	private:
		int m_status, m_k_value, m_external_temp, m_internal_temp, m_consumption, m_time, m_work_time, m_same_temp_time;

		/*private constractor xwris orismata. Den theloume na mporei na dimiourgithei ontotita tis klasis xwris stoixeia*/
		Radiator(){}
	public:
		/*public constructor. pairnei orisma osa xriazetai gia na leitourgisei to kalorifer*/
		Radiator(int status,int k_value, int ext_t, int intern_t);


		/* Medothoi: Prosferoun pliri leitourgikotita panw stin klassi tou kalorifer.
		 * oi perissoteres orizontai sto arxeio radiator.cpp.
		 * Kapoies methodoi pou den exoun logiki simasia den exoun oristei opws px i dinatotita na pigainei
		 * o xronos pros ta piso, i na to na ginetai set stin katanalwsi klp
		 */

		void calculateAndSetConsumption(void);

		int getConsumption(void){return m_consumption;};

		void goOneHourLater(void);

		int getHours(void){return m_time;}

		int getWorkingHours(void){return m_work_time;}

		int getSameTempHours(void){return m_same_temp_time;}

		void setStatus(int status);

		int getStatus(void){return m_status;}

		void setExtTemp(int temp);

		void setIntTemp(int temp);

		int getExtTemp(void){return m_external_temp;}

		int getIntTemp(void){return m_internal_temp;}		

		void increaseExtTemp(int temp);

		void decreaseExtTemp(int temp);

		void increaseIntTemp(int temp);

		void decreaseIntTemp(int temp);

		void printRadiatorSettings(void);

};

#endif

