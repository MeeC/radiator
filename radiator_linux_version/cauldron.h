#ifndef CAULDRON_H
#define CAULDRON_H

/*dilwsei tis klasis Cauldron aka kazani*/
class Cauldron
{
	/*private metavlites prosvasimes mono apo tin klasi kazani*/
	private:
		int m_capacity, m_oil;

		/*private constractor xwris orismata. Den theloume na mporei na dimiourgithei ontotita tis klasis xwris xwritikota*/
		Cauldron(){}
	public:
		/*public constructor. pairnei orisma tin xwritikotita tou kazaniou*/
		Cauldron(int capacity){m_capacity=capacity;}
		
		/*kai allos constructor pou pairnei kai deftero orisma to petrelaio pou exei arxika*/
		Cauldron(int capacity, int oil);


		/*Methodoi*/

		void setOil(int oil){m_oil=oil;}

		int getOil(void){return m_oil;}

		/*an kai den exei efarmogi stin pragmatikota, ypothetoume oti mporoume na allaksoume kai tin xwritikotita tou kazaniou*/
		void setCapacity(int capacity){m_capacity=capacity;}

		int getCapacity(void){return m_capacity;}		
				
		void addOil(int oil);

		void removeOil(int oil);

		bool isEmpty(void);

		bool isFull(void);

		void fullUP(void){m_oil=m_capacity;}

		void emptyKazani(void){m_oil=0;}

		void printStatus(void);


};

#endif

