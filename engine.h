#ifndef ENGINE_H_
#define ENGINE_H_
#include <queue>
#include <iostream>
#include <string>
#include <vector>
#include "buyorder.h"
#include "sellorder.h"
using namespace std;
/** This is the header file for the main matching engine code
 *  Written by: Timothy Daisuke Chon
 *  Date: 9/15/2023
*/
class Engine {
	public:
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
		priority_queue<BuyOrder, vector<BuyOrder>, buyOrderPriority> buyOrders;
		priority_queue<SellOrder, vector<SellOrder>, sellOrderPriority> sellOrders;
		// TODO: A matching engine would require the following data on buy orders: Username, User prestige, Asset name, Asset quantity required to be filled, price
		// TODO: A matching engine would require the following data on sell orders: Username, User prestige, Asset name, Asset quantity required to be filled, price
		// Design: Matching engine will currently prioritize based on user prestige (prestige defined as how many successful transactions the user has had)
		Engine();

		Engine(vector<BuyOrder> buyers, vector<SellOrder> sellers);

		Engine(priority_queue<BuyOrder, vector<BuyOrder>, buyOrderPriority> buyers, 
			 priority_queue<SellOrder, vector<SellOrder>, sellOrderPriority> sellers);

		priority_queue<BuyOrder, vector<BuyOrder>, buyOrderPriority> getBuyers();

		priority_queue<SellOrder, vector<SellOrder>, sellOrderPriority> getSellers();

		void setBuyers(priority_queue<BuyOrder> buyOrders);

		void setSellers(priority_queue<SellOrder> sellOrders);

		void addBuyOrder(BuyOrder buyer);

		void addSellOrder (SellOrder seller);

		void deleteBuyOrder(BuyOrder buyer);

		void deleteSellorder(SellOrder seller);

		void match();


		// TODO: Define a function that takes an input file and puts orders onto the relevant pqueue

		// TODO: Define a function that matches orders
};

#endif // ENGINE_H_