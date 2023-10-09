#ifndef ENGINE_H_
#define ENGINE_H_
#include <queue>
#include <iostream>
#include <string>
#include <vector>
#include "buyorder.h"
#include "sellorder.h"
#include "engine.h"
/** This is the header file for the main matching engine code
 *  Written by: Timothy Daisuke Chon
 *  Date: 9/15/2023
*/
class Engine {
	public:
		//Define custom prioritization based on user prestige
		struct buyOrderPriority {

		};

		struct sellOrderPriority {

		};

		//PQueues for buy orders and sell orders
		std::priority_queue<BuyOrder, std::vector<BuyOrder>, buyOrderPriority> buyOrders;
		std::priority_queue<SellOrder, std::vector<SellOrder>, sellOrderPriority> sellOrders;
		// TODO: A matching engine would require the following data on buy orders: Username, User prestige, Asset name, Asset quantity required to be filled, price
		// TODO: A matching engine would require the following data on sell orders: Username, User prestige, Asset name, Asset quantity required to be filled, price
		// Design: Matching engine will currently prioritize based on user prestige (prestige defined as how many successful transactions the user has had)
		Engine() {

		}

		Engine(std::vector<BuyOrder> buyers, std::vector<SellOrder> sellers) {

		}

		Engine(std::priority_queue<BuyOrder> buyers, std::priority_queue<SellOrder> sellers) {

		}

		std::priority_queue<BuyOrder> getBuyers() {

		}

		std::priority_queue<SellOrder> getSellers() {

		}

		void setBuyers(std::priority_queue<BuyOrder> buyOrders) {

		}

		void setSellers(std::priority_queue<SellOrder> sellOrders) {

		}

		void addBuyOrder(BuyOrder buyer){

		}

		void addSellOrder (SellOrder seller) {

		}

		void deleteBuyOrder(BuyOrder buyer) {

		}

		void deleteSellorder(SellOrder seller) {

		}

		void match() {

		}

		void terminate() {

		}

		// TODO: Define a function that takes an input file and puts orders onto the relevant pqueue

		// TODO: Define a function that matches orders
};

#endif // ENGINE_H_