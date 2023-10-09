#include <iostream>
#include <string>
#include "sellorder.h"
using namespace std;
/** This is the file for sell order data code
 *  Written by: Timothy Daisuke Chon
 *  Date: 10/4/2023
*/

SellOrder::SellOrder(string username, float prestige, int quantity, int price) {
	sellerName = username;
	sellerPrestige = prestige;
	sellerQuantity = quantity;
	sellerPrice = price;
}

SellOrder::~SellOrder() {	
}

void SellOrder::printOrder() {
	cout << "Sell Order for " + this->sellerName + ": " << endl;
	cout << "Prestige: " + to_string(this->sellerPrestige) << endl;
	cout << "Quantity: " + to_string(this->sellerQuantity) << endl;
	cout << "Price: " + to_string(this->sellerPrice) << endl;
	return;
}

		// check if overlap with buy order functions causes problems
string SellOrder::getUsername() {
	return this->sellerName;
}

float SellOrder::getPrestige() {
	return this->sellerPrestige;
}

int SellOrder::getQuantity() {
	return this->sellerQuantity;
}

int SellOrder::getPrice() {
	return this->sellerPrice;
}

void SellOrder::setSellOrder(string username, float prestige, int quantity, int price) {
	this->sellerName = username;
	this->sellerPrestige = prestige;
	this->sellerQuantity = quantity;
	this->sellerPrice = price;
}

