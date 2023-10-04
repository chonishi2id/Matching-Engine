#include <queue>
#include <iostream>
#include <string>
#include "buyorder.h"
#include "sellorder.h"
#include "engine.h"
/** This is the header file for the main matching engine code
 *  Written by: Timothy Daisuke Chon
 *  Date: 9/15/2023
*/
class Engine {
	public:
		//PQueues for buy orders and sell orders
		std::priority_queue<BuyOrder> buyOrders;
		std::priority_queue<SellOrder> sellOrders;
		// TODO: A matching engine would require the following data on buy orders: Username, User prestige, Asset name, Asset quantity required to be filled, price
		// TODO: A matching engine would require the following data on sell orders: Username, User prestige, Asset name, Asset quantity required to be filled, price
		// Design: Matching engine will currently prioritize based on user prestige (prestige defined as how many successful transactions the user has had)
		Engine(std::priority_queue<BuyOrder> buyers, std::priority_queue<SellOrder> sellers) {
			buyOrders = buyers;
			sellOrders = sellers;
		}

		std::priority_queue<BuyOrder> getBuyers() {
			return this->buyOrders;
		}

		std::priority_queue<SellOrder> getSellers() {
			return this->sellOrders;
		}

		void setBuyers(std::priority_queue<BuyOrder> buyOrders) {
			this->buyOrders = buyOrders;
		}

		void setSellers(std::priority_queue<SellOrder> sellOrders) {
			this->sellOrders = sellOrders;
		}

		void addBuyOrder(BuyOrder buyer){
			this->buyOrders.push(buyer);
		}

		void addSellOrder (SellOrder seller) {
			this->sellOrders.push(seller);
		}
		
		void deleteBuyOrder() {

		}

		void deleteSellOrder() {
			
		}

		void match() {

		}

		// TODO: Define a function that takes an input file and puts orders onto the relevant pqueue

		// TODO: Define a function that matches orders
};