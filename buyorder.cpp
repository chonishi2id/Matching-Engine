#include <iostream>
#include <string>
#include "buyorder.h"

/** This is the file for buy order data code
 *  Written by: Timothy Daisuke Chon
 *  Date: 10/4/2023
*/

class BuyOrder {
	private:
		std::string buyerName;
		int buyerPrestige;
		int buyerQuantity;
		int buyerPrice;
		
		BuyOrder(std::string username, int prestige, int quantity, int price) {
			 buyerName = username;
			 buyerPrestige = prestige;
			 buyerQuantity = quantity;
			 buyerPrice = price;
		}

		// check if overlap with sell order functions causes problems
		std::string getUsername() {
			return this->buyerName;
		}

		int getPrestige() {
			return this->buyerPrestige;
		}

		int getQuantity() {
			return this->buyerQuantity;
		}

		int getPrice() {
			return this->buyerPrice;
		}

		void setBuyOrder(std::string username, int prestige, int quantity, int price) {
			this->buyerName = username;
			this->buyerPrestige = prestige;
			this->buyerQuantity = quantity;
			this->buyerPrice = price;
		}

		void deleteBuyOrder() {
			//look up how to delete things
		}							

		// TODO: Define a function that takes an input file and puts orders onto the relevant pqueue
		
		// TODO: Define a function that matches orders
};