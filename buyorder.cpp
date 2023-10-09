#include <iostream>
#include <string>
#include "buyorder.h"
using namespace std;
/** This is the file for buy order data code
 *  Written by: Timothy Daisuke Chon
 *  Date: 10/4/2023
*/

BuyOrder::BuyOrder(string username, float prestige, int quantity, int price) {
	 buyerName = username;
	 buyerPrestige = prestige;
	 buyerQuantity = quantity;
	 buyerPrice = price;
}

BuyOrder::~BuyOrder() {
}

void BuyOrder::printOrder() {
	cout << "Buy Order for " + this->buyerName + ": " << endl;
	cout << "Prestige: " + to_string(this->buyerPrestige) << endl;
	cout << "Quantity: " + to_string(this->buyerQuantity) << endl;
	cout << "Price: " + to_string(this->buyerPrice) << endl;
	return;
}

		// check if overlap with sell order functions causes problems
string BuyOrder::getUsername() {
	return this->buyerName;
}

float BuyOrder::getPrestige() {
	return this->buyerPrestige;
}

int BuyOrder::getQuantity() {
	return this->buyerQuantity;
}

int BuyOrder::getPrice() {
	return this->buyerPrice;
}

void BuyOrder::setBuyOrder(string username, float prestige, int quantity, int price) {
	this->buyerName = username;
	this->buyerPrestige = prestige;
	this->buyerQuantity = quantity;
	this->buyerPrice = price;
}
