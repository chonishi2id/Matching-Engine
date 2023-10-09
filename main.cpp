#include <iostream>
#include <queue>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "buyorder.h"
#include "buyorder.cpp"
#include "sellorder.h"
#include "sellorder.cpp"
//#include "engine.h"

using namespace std;

int main() {

	// We get the buy orders from a file and put them in a vector
	ifstream buyerFile;
	buyerFile.open("buyorders.csv");
	string line;
	vector<BuyOrder*> buyOrders;
	getline(buyerFile, line);
	while(getline(buyerFile, line)) {
		string username;
		float prestige;
		int quantity;
		int price;
		string temp;

		// extract username
		stringstream inputString(line);
		getline(inputString, username, ',');

		//extract prestige
		getline(inputString, temp, ',');
		prestige = atof(temp.c_str());

		// extract quantity
		getline(inputString, temp, ',');
		quantity = atoi(temp.c_str());

		//extract price;
		getline(inputString, temp, ',');
		price = atoi(temp.c_str());

		BuyOrder* curOrder = new BuyOrder(username, prestige, quantity, price);
		curOrder->printOrder();

		buyOrders.push_back(curOrder);
	}
	cout << "Size of buyorders: " + to_string(buyOrders.size()) << endl;
	BuyOrder* firstBuy = buyOrders.front();
	firstBuy->printOrder();
	buyerFile.close();

	// We get the sell orders from a file and put that in a vector too
	ifstream sellerFile;
	sellerFile.open("sellorders.csv");
	vector<SellOrder*> sellOrders;
	line = "";
	getline(sellerFile, line);
	while(getline(sellerFile, line)) {
		string username;
		float prestige;
		int quantity;
		int price;
		string temp;

		// extract username
		stringstream inputString(line);
		getline(inputString, username, ',');

		//extract prestige
		getline(inputString, temp, ',');
		prestige = atof(temp.c_str());

		// extract quantity
		getline(inputString, temp, ',');
		quantity = atoi(temp.c_str());

		//extract price;
		getline(inputString, temp, ',');
		price = atoi(temp.c_str());

		SellOrder* curOrder = new SellOrder(username, prestige, quantity, price);
		curOrder->printOrder();

		sellOrders.push_back(curOrder);
	}
	cout << "Size of sellOrders: " + to_string(buyOrders.size()) << endl;
	SellOrder* firstSell = sellOrders.front();
	firstSell->printOrder();
	sellerFile.close();


	// Now we try to match
	return 0;
}