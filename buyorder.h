#ifndef BUYORDER_H_
#define BUYORDER_H_
#include <iostream>
#include <string>
using namespace std;
/** This is the header file for buy order data code
 *  Written by: Timothy Daisuke Chon
 *  Date: 9/15/2023
*/
// User orders 
class BuyOrder {
	private:
		string buyerName;
		float buyerPrestige;
		int buyerQuantity;
		int buyerPrice;

	public:	
		BuyOrder(string username, float prestige, int quantity, int price);

		~BuyOrder();

		void printOrder();

		// check if overlap with sell order functions causes problems
		string getUsername();

		float getPrestige();

		int getQuantity();

		int getPrice();

		void setBuyOrder(string username, float prestige, int quantity, int price);


		// TODO: Define a function that takes an input file and puts orders onto the relevant pqueue
		
		// TODO: Define a function that matches orders
};

#endif // BUYORDER_H_