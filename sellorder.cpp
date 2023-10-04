#include <iostream>
#include <string>
#include "sellorder.h"

/** This is the file for sell order data code
 *  Written by: Timothy Daisuke Chon
 *  Date: 10/4/2023
*/

class SellOrder {
	private:
		std::string sellerName;
		int sellerPrestige;
		int sellerQuantity;
		int sellerPrice;
		
		SellOrder(std::string username, int prestige, int quantity, int price) {
			sellerName = username;
			sellerPrestige = prestige;
			sellerQuantity = quantity;
			sellerPrice = price;
		}

		// check if overlap with buy order functions causes problems
		std::string getUsername() {
			return this->sellerName;
		}

		int getPrestige() {
			return this->sellerPrestige;
		}

		int getQuantity() {
			return this->sellerQuantity;
		}

		int getPrice() {
			return this->sellerPrice;
		}

		void setSellOrder(std::string username, int prestige, int quantity, int price) {
			this->sellerName = username;
			this->sellerPrestige = prestige;
			this->sellerQuantity = quantity;
			this->sellerPrice = price;
		}

		void deleteSellOrder(SellOrder seller) {
			// look up how to delete stuff
		}

		// TODO: Define a function that takes an input file and puts orders onto the relevant pqueue
		
		// TODO: Define a function that matches orders
};

