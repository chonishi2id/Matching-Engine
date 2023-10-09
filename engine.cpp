#include <queue>
#include <iostream>
#include <string>
#include <vector>
#include "buyorder.h"
#include "sellorder.h"
#include "engine.h"
using namespace std;
/** This is the file for the main matching engine code
 *  Written by: Timothy Daisuke Chon
 *  Date: 9/15/2023
*/

//Define custom prioritization based on user prestige
struct buyOrderPriority {
	bool operator()(BuyOrder order1, BuyOrder order2) {
		return order1.getPrestige() > order2.getPrestige();
	} 
};

struct sellOrderPriority {
	bool operator()(SellOrder order1, SellOrder order2) {
		return order1.getPrestige() > order2.getPrestige();
	}
};
//PQueues for buy orders and sell orders
//priority_queue<BuyOrder, std::vector<BuyOrder>, buyOrderPriority> buyOrders;
//priority_queue<SellOrder, std::vector<SellOrder>, sellOrderPriority> sellOrders;
// TODO: A matching engine would require the following data on buy orders: Username, User prestige, Asset name, Asset quantity required to be filled, price
// TODO: A matching engine would require the following data on sell orders: Username, User prestige, Asset name, Asset quantity required to be filled, price
// Design: Matching engine will currently prioritize based on user prestige (prestige defined as how many successful transactions the user has had)
// Default constructor
Engine::Engine() {
}
// Constructor if given input from a file. If data is given from file, convert to proper data type and then pass to engine
Engine::Engine(vector<BuyOrder> buyers, vector<SellOrder> sellers) {
	for(int i = 0; i < buyers.size(); i++) {
	buyOrders.push(buyers[i]);
	}
	for(int j = 0; j < sellers.size(); j++) {
		sellOrders.push(sellers[j]);
	}
}

// Constructor if priority queues are given
Engine::Engine(priority_queue<BuyOrder, vector<BuyOrder>, buyOrderPriority> buyers, 
			 priority_queue<SellOrder, vector<SellOrder>, sellOrderPriority> sellers) {
	buyOrders = buyers;
	sellOrders = sellers;
}

priority_queue<BuyOrder, vector<BuyOrder>, buyOrderPriority> Engine::getBuyers() {
	return this->buyOrders;
}

priority_queue<SellOrder, vector<SellOrder>, sellOrderPriority> getSellers() {
	return this->sellOrders;
}

void Engine::setBuyers(priority_queue<BuyOrder, vector<BuyOrder>, buyOrderPriority> buyOrders) {
	this->buyOrders = buyOrders;
}

void setSellers(priority_queue<SellOrder, vector<SellOrder>, sellOrderPriority> sellOrders) {
	this->sellOrders = sellOrders;
}

void addBuyOrder(BuyOrder buyer){
	this->buyOrders.push(buyer);
}

void addSellOrder (SellOrder seller) {
	this->sellOrders.push(seller);
}

void match() {
	// check if buyorders and sellorders actually have orders
	if(buyOrders.empty() == true) {
		std::cout << "Buy Orders Empty!" << std::endl;
		return;
	}
	else if (sellOrders.empty() == true) {
		std::cout << "Sell Orders Empty!" << std::endl;
		return;
	}
	// Commence matching. 
	// Design: Match sell orders to buy orders. Sellers can wait but buyers want instant gratification
	while(buyOrders.empty() == false) {
		// Note: check if data works correctly
		// Grab buy order stats
		BuyOrder curBuyer = buyOrders.top();
		int buyerQuantity = curBuyer.getQuantity();
		std::string buyername = curBuyer.getUsername();
		// Start matching however many sell orders you can to the buy orer
		while(sellOrders.empty() == false) {
			// Grab sell order stats
			SellOrder curSeller = sellOrders.top();
			int sellerQuantity = curSeller.getQuantity();
			std::string sellername = curSeller.getUsername();
			// Case 1: buyer quantity is equal to seller quantity
			if(buyerQuantity == sellerQuantity) {
				// we pop both parties and proceed with the next buyer
				buyOrders.pop();
				cout << buyername + "'s buy order is fulfilled!" << endl;
				cout << sellername + "'s sell order is fulfilled!" << endl;
				sellOrders.pop();
				break;
			}

			// Case 2: Buyer quantity is less than seller quantity
			// We subtract SellOrder object's quantity value by BuyOrder object's quantity and put it back in pqueue
			else if(buyerQuantity < sellerQuantity) {
				buyOrders.pop();
				cout << buyername + "'s buy order is fulfilled!" << std::endl;
				sellerQuantity -= buyerQuantity;
				cout << sellername + "'s sell order has " + std::to_string(sellerQuantity) + " orders left!" <<std::endl;
				curSeller.setSellOrder(sellername, curSeller.getPrestige(), sellerQuantity, curSeller.getPrice());
				// May be unnecessary
				//sellOrders.pop();
				//sellOrders.push(curSeller);
				break;
			}

			// Case 3: Buyer quantity is more than seller quantity
			buyerQuantity -= sellerQuantity;
			cout << buyername + "'s buy order has " + to_string(buyerQuantity) + " orders left!" <<endl;
			cout << sellername + "'s sell order is fulfilled!" << endl;
			sellOrders.pop();
		}
		// Note: might need to do mem management here
	}
	cout<< "The engine has finished matching. Goodbye!" <<endl;
}
