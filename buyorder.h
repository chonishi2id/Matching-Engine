#ifndef BUYORDER_H_
#define BUYORDER_H_
#include <iostream>
#include <string>
/** This is the header file for buy order data code
 *  Written by: Timothy Daisuke Chon
 *  Date: 9/15/2023
*/
// User orders 
class BuyOrder {
	private:
		std::string username;
		int prestige;
		int quantity;
		int price;
		
		BuyOrder(std::string username, int prestige, int quantity, int price) {
			
		}

		// TODO: Define a function that takes an input file and puts orders onto the relevant pqueue
		
		// TODO: Define a function that matches orders
};

#endif // BUYORDER_H_