#ifndef SELLORDER_H_
#define SELLORDER_H_
#include <iostream>
#include <string>
/** This is the header file for sell order data code
 *  Written by: Timothy Daisuke Chon
 *  Date: 9/15/2023
*/
// User orders 
class SellOrder {
	private:
		std::string sellerName;
		float sellerPrestige;
		int sellerQuantity;
		int sellerPrice;

	public:	
		SellOrder(std::string username, float prestige, int quantity, int price) {
			
		}

		~SellOrder() {
			
		}
		// check if overlap with buy order functions causes problems
		std::string getUsername() {

		}

		float getPrestige() {

		}

		int getQuantity() {

		}

		int getPrice() {

		}

		void setSellOrder(std::string username, float prestige, int quantity, int price) {

		}

		void deleteSellOrder(SellOrder seller) {

		}

		// TODO: Define a function that takes an input file and puts orders onto the relevant pqueue
		
		// TODO: Define a function that matches orders
};

#endif // SELLORDER_H_