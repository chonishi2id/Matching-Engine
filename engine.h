#ifndef ENGINE_H_
#define ENGINE_H_
#include <queue>
/** This is the header file for the main matching engine code
 *  Written by: Timothy Daisuke Chon
 *  Date: 9/15/2023
*/
class Engine {
	public:
		// TODO: Define two pQueues: One for buy orders and one for sell orders
		// TODO: A matching engine would require the following data on buy orders: Username, User prestige, Asset name, Asset quantity required to be filled, price
		// TODO: A matching engine would require the following data on sell orders: Username, User prestige, Asset name, Asset quantity required to be filled, price
		// Design: Matching engine will currently prioritize based on user prestige (prestige defined as how many successful transactions the user has had)
		Engine() {

		}

		// TODO: Define a function that takes an input file and puts orders onto the relevant pqueue

		// TODO: Define a function that matches orders
};

#endif // ENGINE_H_